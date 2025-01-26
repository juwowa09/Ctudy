#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> adj[201];
int dist1[201];
int dist2[201];
int dist3[201];
int num = 0, result = 0x7FFFFFFF;

void dijkstra(int st, int dist[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});

    fill(dist, dist + num + 1, 0x7FFFFFFF);
    dist[st] = 0;

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();

        if (dist[f.second] < f.first)
            continue;

        for (auto it : adj[f.second])
        {
            if (dist[it.first] <= dist[f.second] + it.second)
                continue;
            pq.push({dist[f.second] + it.second, it.first});
            dist[it.first] = dist[f.second] + it.second;
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;

    num = n;
    for (int i = 0; i < fares.size(); i++)
    {
        adj[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        adj[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }

    dijkstra(s, dist1);
    dijkstra(a, dist2);
    dijkstra(b, dist3);

    for (int i = 1; i <= n; i++)
        result = min(result, dist1[i] + dist2[i] + dist3[i]);

    answer = result;
    return answer;
}