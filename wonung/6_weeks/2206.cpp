#include <iostream>
#include <queue>
using namespace std;

// 이동 가능한 좌표값
pair<int, int> dir[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};

// 벽을 부순 후 visit 처리를 진행해 나갈 공간,
// 부수기 전 visit 처리를 진행할 공간을 나눔
// visit 에 현재까지 진행된 거리를 담아둠.
int visited[1000][1000][2] = {
    0,
};

// map
char m[1000][1000];

int bfs(int row, int col)
{
    // 좌표값 pair 와 벽을 부순 상태를 나누기 위한 int를 pair 로 묶어주었다.
    // 부순 상태를 0,
    // 부수지 않은 상태를 1로 나눔
    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, 1});

    // 처음에는 부수지 않은 상태 1 에서 진행

    visited[0][0][1] = 1;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int nrow = q.front().first.first + dir[i].first;
            int ncol = q.front().first.second + dir[i].second;

            // 현재 벽을 처리한 상태에서 visit 처리가 이루어졌거나
            if (nrow < 0 || nrow >= row || ncol < 0 || ncol >= col || visited[nrow][ncol][q.front().second] != 0)
                continue;

            // 다음 map 이 0 이면 바로 진행 가능.
            if (m[nrow][ncol] == '0')
            {
                // 현재 상태 q.front().second 에 따라 visit 처리를 나누어줌.
                visited[nrow][ncol][q.front().second] = visited[q.front().first.first][q.front().first.second][q.front().second] + 1;
                ;
                q.push({{nrow, ncol}, q.front().second});
            }

            // 다음 map 1, 현재 상태가 벽을 부수기 전 1 이면 부수면서 진행 가능.
            // visit 처리는 부수고 난 후 (0) 로 처리한다.
            if (m[nrow][ncol] == '1' && q.front().second == 1)
            {
                visited[q.front().first.first][q.front().first.second][0] = visited[q.front().first.first][q.front().first.second][q.front().second];

                // visit 처리는 부수고 난 후 (0) 로 처리한다.
                visited[nrow][ncol][0] = visited[q.front().first.first][q.front().first.second][q.front().second] + 1;
                q.push({{nrow, ncol}, q.front().second - 1});
            }
        }
        // 끝지점에 처음 도달한 경우 바로 return 진행
        if (q.front().first.first == row - 1 && q.front().first.second == col - 1)
        {
            return visited[q.front().first.first][q.front().first.second][q.front().second];
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