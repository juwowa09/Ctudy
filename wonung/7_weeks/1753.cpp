#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<pair<int, int>> *v, int n, int st, int *d)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i <= n; i++)
        d[i] = 100000000;

    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty())
    {
        auto a = pq.top();
        pq.pop();
        if (d[a.second] != a.first)
            continue;
        for (vector<pair<int, int>>::iterator it = v[a.second].begin(); it != v[a.second].end(); it++)
        {
            if (d[it->first] <= a.first + it->second)
                continue;
            d[it->first] = a.first + it->second;
            pq.push({d[it->first], it->first});
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e, st, u, w, m;
    int dist[20001];
    vector<pair<int, int>> v[20001];
    cin >> n >> e >> st;

    for (int i = 0; i < e; i++)
    {
        cin >> u >> m >> w;
        v[u].push_back({m, w});
    }
    dijkstra(v, n, st, dist);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 100000000)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}