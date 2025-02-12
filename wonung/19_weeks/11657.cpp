#include <iostream>
#include <queue>
using namespace std;

int n, m;
long long dist[501];
vector<pair<int, int>> adj[501];

bool bell()
{
    fill(dist, dist + n + 1, 0x7FFFFFFF);

    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto it : adj[j])
            {
                if (dist[j] != 0x7FFFFFFF &&
                    dist[it.second] > dist[j] + it.first)
                    dist[it.second] = dist[j] + it.first;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            if (dist[i] != 0x7FFFFFFF &&
                dist[it.second] > dist[i] + it.first)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    if (bell())
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] != 0x7FFFFFFF)
                cout << dist[i] << "\n";
            else
                cout << -1 << "\n";
        }
    }
    else
        cout << -1;
}