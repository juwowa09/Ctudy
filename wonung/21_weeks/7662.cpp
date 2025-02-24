#include <string>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int> maxq;
map<int, int> Map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;

    cin >> T;
    for (int test = 0; test < T; test++)
    {
        cin >> n;
        cin.ignore();

        Map.clear();
        while (!maxq.empty())
            maxq.pop();
        while (!minq.empty())
            minq.pop();

        for (int i = 0; i < n; i++)
        {
            string it;
            getline(cin, it);

            string op = it.substr(0, 1);
            int num = stoi(it.substr(2));
            if (op == "I")
            {
                minq.push(num);
                maxq.push(num);
                Map[num]++;
            }
            else if (op == "D")
            {
                if (minq.empty() || maxq.empty())
                {
                    continue;
                }
                if (num == -1)
                {
                    Map[minq.top()]--;
                    minq.pop();
                }
                else
                {
                    Map[maxq.top()]--;
                    maxq.pop();
                }
                while (!maxq.empty() && Map[maxq.top()] == 0)
                    maxq.pop();
                while (!minq.empty() && Map[minq.top()] == 0)
                    minq.pop();
            }
        }

        if (minq.empty() && maxq.empty())
            cout << "EMPTY\n";
        else
            cout << maxq.top() << " " << minq.top() << "\n";
    }
}