#include <iostream>
using namespace std;

int dp[1002][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        dp[i][9] = dp[i - 1][9];
        for (int j = 8; j >= 0; j--)
            dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % 10007;
    }
    cout << dp[n + 1][0];
}