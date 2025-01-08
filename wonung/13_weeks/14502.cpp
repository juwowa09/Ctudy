#include <iostream>
#include <queue>

using namespace std;

int result = 0;
int map1[8][8];
int map2[8][8];
int n, m;

pair<int, int> pos[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

void bfs()
{
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map1[i][j] == 2)
            {
                q.push({i, j});
            }
            map2[i][j] = map1[i][j];
        }
    }
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        int nrow;
        int ncol;
        for (int i = 0; i < 4; i++)
        {
            nrow = f.first + pos[i].first;
            ncol = f.second + pos[i].second;
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                continue;
            if (map2[nrow][ncol] == 2)
                continue;
            if (map2[nrow][ncol] == 0)
            {
                map2[nrow][ncol] = 2;
                q.push({nrow, ncol});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map2[i][j] == 0)
                cnt++;
        }
    }
    result = max(result, cnt);
}

void wall(int cnt, int r, int c)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }
    for (int i = r; i < n; i++)
    {
        for (int j = (i == r ? c : 0); j < m; j++)
        {
            if (map1[i][j] == 0)
            {
                map1[i][j] = 1;
                wall(cnt + 1, i, j);
                map1[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map1[i][j];
        }
    }
    wall(0, 0, 0);
    cout << result;
}