#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> ind;
vector<int> v;
vector<int> dp;
int n;

void topological()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i : adj[f])
        {
            ind[i]--;
            // 항상 더 오래걸리는 시간으로 세팅.
            dp[i] = max(dp[i], dp[f] + v[f]);
            if (ind[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> n;
    v.resize(n + 1);
    adj.resize(n + 1);
    ind.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        while (1)
        {
            cin >> k;
            if (k == -1)
                break;
            adj[k].push_back(i);
            ind[i]++;
        }
    }

    topological();
    for (int i = 1; i <= n; i++)
        cout << dp[i] + v[i] << "\n";
}