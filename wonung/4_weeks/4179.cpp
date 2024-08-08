#include <iostream>
#include <queue>
using namespace std;

pair<int, int> pos[4] = {
    make_pair(1, 0),
    make_pair(-1, 0),
    make_pair(0, 1),
    make_pair(0, -1),
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    pair<int, int> jihun;
    string input;
    queue<pair<int, int>> q;

    cin >> n >> m;
    char **arr = new char *[n];
    int **visit = new int *[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[i] = new char[m];
        visit[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = 0;
            arr[i][j] = input[j];
            if (input[j] == 'J')
                jihun = make_pair(i, j);
            if (input[j] == 'F')
                q.push(make_pair(i, j));
        }
    }
    q.push(jihun);
    visit[jihun.first][jihun.second] = 1;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int row = q.front().first + pos[i].first;
            int col = q.front().second + pos[i].second;
            if (arr[q.front().first][q.front().second] == 'J' &&
                (q.front().first == 0 || q.front().first == n - 1 ||
                 q.front().second == 0 || q.front().second == m - 1))
            {
                cout << visit[q.front().first][q.front().second];
                return 0;
            }
            if (row >= 0 && row < n && col >= 0 && col < m &&
                !visit[row][col] && arr[row][col] == '.')
            {
                if (arr[q.front().first][q.front().second] == 'F')
                {
                    arr[row][col] = 'F';
                    q.push({row, col});
                }
                if (arr[q.front().first][q.front().second] == 'J')
                {
                    arr[row][col] = 'J';
                    q.push({row, col});
                    visit[row][col] = visit[q.front().first][q.front().second] + 1;
                }
            }
        }
        q.pop();
    }
    cout << "IMPOSSIBLE";
}