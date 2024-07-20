#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> q;
    deque<int> number;
    int n, k, it, temp1, temp2;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        q.push_back(i);
        number.push_back(k);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        it = number.front();
        q.pop_front();
        number.pop_front();
        if (it > 0)
            it -= 1;
        else if (it < 0)
        {
            while (it < 0 && q.size())
                it += q.size();
        }
        for (int i = 0; i < it; i++)
        {
            temp1 = q.front();
            temp2 = number.front();
            q.push_back(temp1);
            number.push_back(temp2);
            q.pop_front();
            number.pop_front();
        }
    }
}
