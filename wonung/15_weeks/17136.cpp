#include <iostream>
using namespace std;

int result = 0x7FFFFFFF;
int map[10][10];
int paper[6];

bool check(int r, int c, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (map[r + i][c + j] == 0)
                return false;
        }
    return true;
}

void dfs(int r, int c, int cnt)
{
    if (c > 9)
    {
        r++;
        c = 0;
    }
    if (r > 9)
    {
        result = min(result, cnt);
        return;
    }
    if (cnt >= result)
        return;

    if (map[r][c])
    {
        for (int size = 5; size > 0; size--)
        {
            if (r + size <= 10 && c + size <= 10 && check(r, c, size) && paper[size] < 5)
            {
                paper[size]++;
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        map[r + i][c + j] = 0;
                dfs(r, c + size - 1, cnt + 1);
                paper[size]--;
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        map[r + i][c + j] = 1;
            }
        }
    }
    else
        dfs(r, c + 1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> map[i][j];

    dfs(0, 0, 0);

    if (result == 0x7FFFFFFF)
        cout << -1;
    else
        cout << result;
}