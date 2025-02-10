#include <iostream>
using namespace std;

int h, w, n;

int Map[1001][1001];
int dp[1001][1001];

void input()
{
    cin >> h >> w >> n;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> Map[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    dp[1][1] = n - 1;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int d = dp[i][j];
            if (d % 2)
            {
                if (Map[i - 1][j - 1])
                    dp[i][j + 1] += 1;
                else
                    dp[i + 1][j] += 1;
            }
            dp[i + 1][j] += d / 2;
            dp[i][j + 1] += d / 2;
        }
    }
    int r = 1, c = 1;

    while (r <= h && c <= w)
    {
        if (dp[r][c] % 2)
        {
            if (Map[r - 1][c - 1])
                r++;
            else
                c++;
        }
        else
        {
            if (Map[r - 1][c - 1])
                c++;
            else
                r++;
        }
    }
    cout << r << " " << c;
}