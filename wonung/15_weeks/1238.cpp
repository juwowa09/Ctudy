#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, result = 0;
vector<pair<int, int>> adj[1001];
int dist1[1001];
int dist2[1001];

void dijkstra(int st, int dir, int *dist)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (cur.first > dist[cur.second])
            continue;
        for (auto child : adj[cur.second])
        {
            if (dir * child.first > 0 && (child.first * dir + dist[cur.second] < dist[child.second]))
            {
                dist[child.second] = child.first * dir + dist[cur.second];
                pq.push({child.first * dir + dist[cur.second], child.second});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p, c, d;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> c >> d;
        adj[p].push_back({d, c});
        adj[c].push_back({-d, p});
    }

    fill(dist1, dist1 + n + 1, 0x7FFFFFFF);
    dijkstra(x, 1, dist1);

    fill(dist2, dist2 + n + 1, 0x7FFFFFFF);
    dijkstra(x, -1, dist2);

    for (int i = 1; i <= n; i++)
        result = max(result, dist1[i] + dist2[i]);
    cout << result;
}