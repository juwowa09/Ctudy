#include <iostream>
using namespace std;

int visit[500][500];
int arr[500][500];

pair<int, int> d[4] = {
    {1, 0},
    {
        -1,
        0,
    },
    {0, 1},
    {0, -1}};

int dfs(int row, int col, int n, int m)
{
    if (row == n - 1 && col == m - 1)
        return 1;
    if (visit[row][col] == -1)
    {
        visit[row][col] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + d[i].first;
            int ncol = col + d[i].second;
            if (nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && arr[nrow][ncol] < arr[row][col])
            {
                visit[row][col] += dfs(nrow, ncol, n, m);
            }
        }
    }
    return visit[row][col];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = -1;
            cin >> arr[i][j];
        }
    }
    cout << dfs(0, 0, n, m);
}