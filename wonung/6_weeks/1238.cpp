#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int *dijkstra(int n, vector<pair<int, int>> *adj, int st, int dir)
{
    int *d;
    d = new int[n + 1];
    fill(d, d + n + 1, 1e9 + 10);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.second] != cur.first)
            continue;
        for (pair<int, int> next : adj[cur.second])
        {
            if (dir * next.first < 0 || d[next.second] <= d[cur.second] + dir * next.first)
                continue;
            d[next.second] = d[cur.second] + dir * next.first;
            pq.push({d[next.second], next.second});
        }
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> *adj;
    int n, x, m, row, col, t, result = 0;
    cin >> n >> m >> x;

    adj = new vector<pair<int, int>>[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> row >> col >> t;
        adj[row].push_back({t, col});
        adj[col].push_back({-t, row});
    }
    int *d1 = dijkstra(n, adj, x, 1);
    int *d2 = dijkstra(n, adj, x, -1);
    for (int i = 1; i <= n; i++)
    {
        if (result < d1[i] + d2[i])
            result = d1[i] + d2[i];
    }
    delete[] adj;
    delete[] d1;
    delete[] d2;
    cout << result << '\n';
}