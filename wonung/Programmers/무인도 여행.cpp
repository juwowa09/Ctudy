#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int visit[100][100] = {
    0,
};

pair<int, int> pos[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(int row, int col, int n, int m, vector<string> maps, int num)
{
    int sum = 0;

    queue<pair<int, int>> q;
    q.push({row, col});
    visit[row][col] = num;

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        sum += maps[f.first][f.second] - 48;

        for (int i = 0; i < 4; i++)
        {
            int r = f.first + pos[i].first;
            int c = f.second + pos[i].second;

            if (r < 0 || r >= n || c < 0 || c >= m || maps[r][c] == 'X' || visit[r][c] != 0)
                continue;
            visit[r][c] = num;
            q.push({r, c});
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    int cnt = 1;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'X' && visit[i][j] == 0)
            {
                answer.push_back(bfs(i, j, maps.size(), maps[i].size(), maps, cnt++));
            }
        }
    }
    if (answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}