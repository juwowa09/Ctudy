#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[1001];
priority_queue<int, vector<int>, less<int>> dist[1001];

void dijkstra()
{
    dist[1].push(0);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        for (auto it : adj[f.second])
        {
            if (dist[it.second].size() < k)
            {
                dist[it.second].push(f.first + it.first);
                pq.push({f.first + it.first, it.second});
            }
            else
            {
                if (f.first + it.first >= dist[it.second].top())
                    continue;
                dist[it.second].push(f.first + it.first);
                dist[it.second].pop();
                pq.push({f.first + it.first, it.second});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() < k)
            cout << -1 << "\n";
        else
            cout << dist[i].top() << "\n";
    }
}