#include <iostream>
#include <queue>
using namespace std;

int v, e, st;
int dist[20001];
vector<pair<int, int>> adj[20001];

void dijkstra(int st)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    fill(dist, dist + 1 + v, 0x7FFFFFFF);
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();

        if (f.first != dist[f.second])
            continue;

        for (auto it : adj[f.second])
        {
            if (dist[it.second] > dist[f.second] + it.first)
            {
                dist[it.second] = dist[f.second] + it.first;
                pq.push({dist[it.second], it.second});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    cin >> st;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    dijkstra(st);
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == 0x7FFFFFFF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}