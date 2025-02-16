#include <iostream>
#include <queue>
#define MAX 0x7FFFFFFF
using namespace std;

int n, e;
int dist[801];
vector<long> dist1;
vector<long> dist2;
vector<pair<int, int>> adj[801];

void dijkstra(int st)
{
    fill(dist, dist + n + 1, MAX);
    dist[st] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({dist[st], st});
    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        if (dist[f.second] != f.first)
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

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int mid1, mid2;
    cin >> mid1 >> mid2;
    dijkstra(mid1);
    dist1.push_back(dist[1]);
    dist1.push_back(dist[mid2]);
    dist1.push_back(dist[n]);
    dijkstra(mid2);
    dist2.push_back(dist[1]);
    dist2.push_back(dist[mid1]);
    dist2.push_back(dist[n]);

    long long result = 0;
    result = min(dist1[0] + dist1[1] + dist2[2], dist2[0] + dist2[1] + dist1[2]);
    if (result >= MAX)
        cout << -1;
    else
        cout << result;
}