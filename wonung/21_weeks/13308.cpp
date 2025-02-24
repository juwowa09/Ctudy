#include <iostream>
#include <queue>
#include <vector>
#define INF 1e15
using namespace std;

int n, m, Mprice = 0;
long long dist[2501][2501]; // i 번째 도시에서 현재 j 가 최소 기름값일 때 전체 cost
int price[2501];
vector<pair<int, int>> adj[2501];

long long dijkstra()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= Mprice; j++)
            dist[i][j] = INF;

    priority_queue<pair<long long, pair<int, int>>,
                   vector<pair<long long, pair<int, int>>>,
                   greater<pair<long long, pair<int, int>>>>
        pq;

    dist[1][price[1]] = 0;
    pq.push({0, {price[1], 1}});

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        int cur = f.second.second;
        int cur_price = f.second.first;
        long long cur_cost = f.first;

        if (cur_cost > dist[cur][cur_price])
            continue;

        if (n == cur)
            return cur_cost;

        for (auto it : adj[cur])
        {
            int n_node = it.second;
            int n_price = min(cur_price, price[n_node]);
            if (dist[n_node][cur_price] <= cur_cost + cur_price * it.first)
                continue;
            dist[n_node][cur_price] = cur_cost + cur_price * it.first;
            pq.push({dist[n_node][cur_price], {n_price, n_node}});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
        Mprice = max(Mprice, price[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cout << dijkstra();
}