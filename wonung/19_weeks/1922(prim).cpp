#include <iostream>
#include <queue>
#define MAX 100000001
using namespace std;

int n, m;
int dist[1001];
bool visited[1001];
vector<pair<int, int>> adj[1001];

void prim()
{
    fill(dist, dist + n + 1, MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto f = pq.top();

        pq.pop();
        if (visited[f.second])
            continue;
        visited[f.second] = true;
        for (auto it : adj[f.second])
        {
            if (dist[it.second] > it.first && !visited[it.second])
            {
                dist[it.second] = it.first;
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

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    prim();

    int result = 0;
    for (int i = 1; i <= n; i++)
        result += dist[i];
    cout << result;
}