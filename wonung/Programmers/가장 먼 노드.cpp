#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> adj[20001];
int visit[20001];
int dist = 0;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    queue<int> q;

    q.push(1);
    visit[1] = 1;

    for (int i = 0; i < edge.size(); i++)
    {
        for (int j = 0; j < edge[i].size(); j++)
        {
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
    }

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (auto it = adj[f].begin(); it != adj[f].end(); it++)
        {
            if (visit[*it] != 0)
                continue;
            visit[*it] = visit[f] + 1;
            dist = max(dist, visit[*it]);
            q.push(*it);
        }
    }

    for (int i = 1; i <= n; i++)
        if (visit[i] == dist)
            answer++;

    return answer;
}