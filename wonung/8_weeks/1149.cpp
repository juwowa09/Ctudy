#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, g, b;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) // dp, 점화식 찾기
    {
        cin >> r >> g >> b;
        dp[i][0] = (dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]) + r;
        dp[i][1] = (dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2]) + g;
        dp[i][2] = (dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]) + b;
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
}