#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> state;
vector<vector<int>> e;
int result = 0;

void dfs(int cur, int sh, int wol, vector<bool> visited)
{
    visited[cur] = true;
    if (state[cur])
        wol += 1;
    else
    {
        sh += 1;
        result = max(result, sh);
    }
    cout << cur << " " << sh << " " << wol << "\n";
    if (wol >= sh)
        return;

    for (auto it : e)
    {
        if (visited[it[0]] && !visited[it[1]])
        {
            vector<bool> n_visited = visited;
            dfs(it[1], sh, wol, n_visited);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    int answer = 0;
    state = info;
    e = edges;

    vector<bool> visited(info.size(), false);
    dfs(0, 0, 0, visited);
    answer = result;
    return answer;
}