#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int bitmap[10][10];
int paper[6] = {
    0,
};
int result = 0x7FFFFFFF;

bool check(int r, int c, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (bitmap[r + i][c + j] == 0)
                return false;
        }
    return true;
}

void dfs(int row, int col, int cnt)
{
    while (bitmap[row][col] == 0)
    {
        col++;
        if (col > 9)
        {
            row++;
            if (row > 9)
            {
                result = min(result, cnt);
                return;
            }
            col = 0;
        }
    }
    if (cnt >= result)
        return;

    for (int i = 5; i > 0; i--)
    {
        if (row + i > 10 || col + i > 10 || paper[i] >= 5)
            continue;

        if (check(row, col, i))
        {
            paper[i]++;
            for (int r = 0; r < i; r++)
                for (int c = 0; c < i; c++)
                {
                    bitmap[row + r][col + c] = 0;
                }

            dfs(row, col, cnt + 1);

            paper[i]--;
            for (int r = 0; r < i; r++)
                for (int c = 0; c < i; c++)
                {
                    bitmap[row + r][col + c] = 1;
                }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> bitmap[i][j];
    dfs(0, 0, 0);
    if (result == 0x7FFFFFFF)
        cout << -1;
    else
        cout << result;
}