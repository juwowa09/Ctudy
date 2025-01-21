#include <iostream>
using namespace std;

int n, m, result = 0;

int map[4][4];
bool bit[4][4];

void dfs(int row, int col)
{
    if (col >= 4)
    {
        row++;
        col = 0;
    }
    if (row >= 4)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int row_sum = 0;
            for (int j = 0; j < m; j++)
            {
                if (!bit[i][j])
                {
                    row_sum = row_sum * 10 + map[i][j];
                }
                else
                {
                    sum += row_sum;
                    row_sum = 0;
                }
            }
            sum += row_sum;
        }
        for (int i = 0; i < m; i++)
        {
            int col_sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (bit[j][i])
                {
                    col_sum = col_sum * 10 + map[j][i];
                }
                else
                {
                    sum += col_sum;
                    col_sum = 0;
                }
            }
            sum += col_sum;
        }
        result = max(result, sum);
        return;
    }
    bit[row][col] = false;
    dfs(row, col + 1);
    bit[row][col] = true;
    dfs(row, col + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            map[i][j] = str[j] - 48;
    }
    dfs(0, 0);
    cout << result;
}