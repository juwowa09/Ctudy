#include <iostream>
using namespace std;

int n, result1 = 0, result2 = 0;
int map[10][10];

bool check(int row, int col)
{
    int r = row;
    int c = col;
    int i = 0;
    while (r - i >= 0 && (c - i >= 0 || c + i < n))
    {
        if (c - i >= 0 && map[r - i][c - i] == 2)
            return false;
        if (c + i < n && map[r - i][c + i] == 2)
            return false;
        i++;
    }
    return true;
}

void dfs(int row, int col, int cnt, int *result)
{
    if (col >= n)
    {
        if (col % 2 == 0)
            col = 1;
        else
            col = 0;
        row++;
    }
    if (row >= n)
    {
        *result = max(*result, cnt);
        return;
    }
    if (map[row][col] == 1 && check(row, col))
    {
        map[row][col] = 2;
        dfs(row, col + 2, cnt + 1, result);
        map[row][col] = 1;
    }
    dfs(row, col + 2, cnt, result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    dfs(0, 0, 0, &result1);
    dfs(0, 1, 0, &result2);
    cout << result1 + result2;
}