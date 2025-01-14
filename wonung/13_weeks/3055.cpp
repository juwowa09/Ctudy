#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char map[50][50];
int visit[50][50];
int r, c, row, col;
vector<pair<int, int>> v;

pair<int, int> pos[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

void bfs()
{
    queue<pair<int, int>> q;
    for (auto it = v.begin(); it != v.end(); it++)
        q.push(*it);
    q.push({row, col});
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = f.first + pos[i].first;
            int ncol = f.second + pos[i].second;

            if (nrow >= r || nrow < 0 || ncol >= c || ncol < 0)
                continue;

            if (map[f.first][f.second] == '*' && map[nrow][ncol] == '.')
            {
                map[nrow][ncol] = '*';
                q.push({nrow, ncol});
            }
            else if (map[f.first][f.second] == 'S')
            {
                if (map[nrow][ncol] == 'D')
                {
                    cout << visit[f.first][f.second] + 1;
                    return;
                }
                if (map[nrow][ncol] == '.')
                {
                    q.push({nrow, ncol});
                    map[nrow][ncol] = 'S';
                    visit[nrow][ncol] = visit[f.first][f.second] + 1;
                }
            }
        }
    }
    cout << "KAKTUS";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                row = i;
                col = j;
            }
            else if (map[i][j] == '*')
                v.push_back({i, j});
        }
    }
    bfs();
}