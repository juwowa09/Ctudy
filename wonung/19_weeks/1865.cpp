#include <iostream>
#include <queue>
using namespace std;

int n, m, w;
int dist[501];
vector<pair<int, int>> adj[501];

bool bell()
{
    fill(dist, dist + n + 1, 3000000);

    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto it : adj[j])
            {
                if (dist[it.second] > dist[j] + it.first)
                    dist[it.second] = dist[j] + it.first;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            if (dist[it.second] > dist[i] + it.first)
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++)
            adj[i].clear();

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        for (int i = 0; i < w; i++)
        {
            cin >> a >> b >> c;
            adj[a].push_back({-c, b});
        }
        if (bell())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}