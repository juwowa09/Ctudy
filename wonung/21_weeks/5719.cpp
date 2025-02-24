#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;

int n, m;
int dist[500];
bool visited[500];
vector<pair<int, int>> adj[500];
vector<int> rev_adj[500];

void dijkstra(int st)
{
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<>>
        pq;
    dist[st] = 0;
    pq.push({dist[st], st});

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        int cur = f.second;
        int cur_dist = f.first;
        if (dist[cur] < cur_dist)
            continue;

        for (auto it : adj[cur])
        {
            if (it.first == INF)
                continue;
            if (dist[it.second] < dist[cur] + it.first)
                continue;

            if (dist[it.second] == dist[cur] + it.first)
            {
                rev_adj[it.second].push_back(cur);
            }
            else
            {
                dist[it.second] = dist[cur] + it.first;
                rev_adj[it.second].clear();
                rev_adj[it.second].push_back(cur);
                pq.push({dist[it.second], it.second});
            }
        }
    }
}

void erase(int st)
{
    if (visited[st])
        return;
    visited[st] = true;
    for (auto it : rev_adj[st])
    {
        for (int i = 0; i < adj[it].size(); i++)
        {
            if (adj[it][i].second == st)
            {
                adj[it][i].first = INF;
                break;
            }
        }
        erase(it);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            rev_adj[i].clear();
            visited[i] = false;
        }
        int st, en;
        cin >> st >> en;

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
        }
        dijkstra(st);
        erase(en);
        dijkstra(st);

        if (dist[en] == INF)
            cout << -1 << "\n";
        else
            cout << dist[en] << "\n";
    }
}