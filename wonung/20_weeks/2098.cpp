#include <iostream>
#define MAX 20000000
using namespace std;

int n;
int Map[16][16];
int dp[16][1 << 16];

int dfs(int cur, int state)
{
    if (dp[cur][state] != -1)
        return dp[cur][state];

    if (state == (1 << n) - 1)
    {
        if (Map[cur][0] == 0)
            return MAX;
        return Map[cur][0];
    }

    dp[cur][state] = MAX;
    for (int i = 0; i < n; i++)
    {
        if (Map[cur][i] == 0 || state & (1 << i))
            continue;
        dp[cur][state] = min(dp[cur][state], Map[cur][i] + dfs(i, state | (1 << i)));
    }
    return dp[cur][state];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Map[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1 << n; j++)
            dp[i][j] = -1;

    cout << dfs(0, 1);
}