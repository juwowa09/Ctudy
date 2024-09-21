#include <iostream>
#include <queue>
using namespace std;

pair<int, int> dir[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};

int visit[1000][1000][2] = {
    0,
};
char m[1000][1000];

int bfs(int row, int col)
{
    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, 1});
    visit[0][0][1] = 1;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int nrow = q.front().first.first + dir[i].first;
            int ncol = q.front().first.second + dir[i].second;

            if (nrow < 0 || nrow >= row || ncol < 0 || ncol >= col || visit[nrow][ncol][q.front().second] != 0)
                continue;

            if (m[nrow][ncol] == '0')
            {
                visit[nrow][ncol][q.front().second] = visit[q.front().first.first][q.front().first.second][q.front().second] + 1;
                ;
                q.push({{nrow, ncol}, q.front().second});
            }
            if (m[nrow][ncol] == '1' && q.front().second == 1)
            {
                visit[q.front().first.first][q.front().first.second][0] = visit[q.front().first.first][q.front().first.second][q.front().second];
                visit[nrow][ncol][0] = visit[q.front().first.first][q.front().first.second][q.front().second] + 1;
                q.push({{nrow, ncol}, q.front().second - 1});
            }
        }
        if (q.front().first.first == row - 1 && q.front().first.second == col - 1)
        {
            return visit[q.front().first.first][q.front().first.second][q.front().second];
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int row, col;
    string input;

    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        cin >> input;
        for (int j = 0; j < col; j++)
        {
            m[i][j] = input[j];
        }
    }
    cout << bfs(row, col);
}
