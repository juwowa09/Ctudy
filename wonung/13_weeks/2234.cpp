#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int visit[50][50];
int room[2501];
int n, m, result1 = 0, result2 = 0, result3 = 0;

pair<int, int> pos[4]{
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0},
};

int bfs(int row, int col, int room_num)
{
    queue<pair<int, int>> q;
    int t, result = 1;
    q.push({row, col});
    visit[row][col] = room_num;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        t = map[f.first][f.second];
        for (int i = 0; i < 4; i++)
        {
            if (t % 2 == 0)
            {
                int nrow = f.first + pos[i].first;
                int ncol = f.second + pos[i].second;
                if (nrow >= m || nrow < 0 || ncol >= n || ncol < 0 || visit[nrow][ncol] != 0)
                {
                    t = t >> 1;
                    continue;
                }
                result = result + 1;
                visit[nrow][ncol] = room_num;
                q.push({nrow, ncol});
            }
            t = t >> 1;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == 0)
            {
                result1++;
                int Rsize = bfs(i, j, result1);
                result2 = max(result2, Rsize);
                room[result1] = Rsize;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t = map[i][j];
            for (int k = 0; k < 4; k++)
            {
                if (t % 2 == 1 && visit[i][j] != visit[i + pos[k].first][j + pos[k].second])
                    result3 = max(result3, room[visit[i][j]] + room[visit[i + pos[k].first][j + pos[k].second]]);
                t = t >> 1;
            }
        }
    }
    cout << result1 << "\n";
    cout << result2 << "\n";
    cout << result3;
}