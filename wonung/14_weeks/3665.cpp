#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, t, m;
int score[501];
int indegree[501];

bool topological()
{
    vector<pair<int, int>> v;
    queue<int> q;
    int pre = -1;

    for (int i = 1; i <= n; i++)
        v.push_back({indegree[i], i});

    sort(v.begin(), v.end(), less<pair<int, int>>());
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it->first == pre)
            return false;
        pre = it->first;
        q.push(it->second);
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        int num, one, two;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            score[num] = i;
            indegree[num] = i - 1;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> one >> two;
            if (score[one] > score[two])
            {
                indegree[one]--;
                indegree[two]++;
            }
            else
            {
                indegree[one]++;
                indegree[two]--;
            }
        }
        if (!topological())
            cout << "IMPOSSIBLE\n";
    }
}