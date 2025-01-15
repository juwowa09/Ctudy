#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> indg;
vector<vector<int>> adj;
queue<int> result;
int n;

void topological()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        result.push(f);
        for (auto it : adj[f])
        {
            indg[it]--;
            if (indg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (result.size() == n)
    {
        while (!result.empty())
        {
            cout << result.front() << "\n";
            result.pop();
        }
    }
    else
    {
        cout << 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, k;
    cin >> n >> m;

    indg.resize(n + 1, 0);
    adj.resize(n + 1);
    while (m--)
    {
        cin >> k;
        int pre = 0, cur;
        for (int i = 0; i < k; i++)
        {
            cin >> cur;
            if (i > 0)
            {
                adj[pre].push_back(cur);
                indg[cur]++;
            }
            pre = cur;
        }
    }

    topological();
}
