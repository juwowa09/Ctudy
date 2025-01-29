// union find
#include <vector>

using namespace std;

int group[200];

int find_g(int x)
{
    if (x != group[x])
        return group[x] = find_g(group[x]);
    return x;
}

bool merge(int x, int y)
{
    int g_x = find_g(x);
    int g_y = find_g(y);

    if (g_x != g_y)
    {
        if (g_x < g_y)
            group[g_y] = g_x;
        else
            group[g_x] = g_y;
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = n;

    for (int i = 0; i < n; i++)
        group[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (computers[i][j] && merge(i, j))
                answer--;
        }
    }
    return answer;
}

// BFS
#include <vector>
#include <queue>
using namespace std;

bool visited[200];
vector<vector<int>> adj;
int num;

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    visited[st] = true;

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        for (int i = 0; i < num; i++)
        {
            if (adj[f][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    adj = computers;
    num = n;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            answer++;
        }
    }

    return answer;
}

// DFS
#include <vector>
#include <queue>
using namespace std;

bool visited[200];
vector<vector<int>> adj;
int num;

void dfs(int st)
{
    visited[st] = true;

    for (int i = 0; i < num; i++)
    {
        if (adj[st][i] && !visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    adj = computers;
    num = n;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            answer++;
        }
    }

    return answer;
}