#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, m;
int dist[1001];
int road[1001];
vector<pair<int, int>> adj[1001];

void dijkstra(int st)
{
    int en = 0, d = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    fill(dist, dist + n + 1, 0x7FFFFFFF);
    dist[st] = 0;
    pq.push({dist[st], st});
    int parent = 0;

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        if (f.first > dist[f.second])
            continue;

        for (auto it : adj[f.second])
        {
            if (dist[it.first] > f.first + it.second)
            {
                road[it.first] = f.second;
                dist[it.first] = f.first + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;

    cin >> n >> m;
    int st, en, k;
    for (int i = 0; i < m; i++)
    {
        cin >> st >> en >> k;
        adj[st].push_back({en, k});
    }
    cin >> st >> en;

    dijkstra(st);
    cout << dist[en] << "\n";
    while (en != 0)
    {
        s.push(en);
        en = road[en];
    }
    cout << s.size() << "\n";

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}