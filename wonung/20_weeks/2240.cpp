#include <iostream>
using namespace std;

int dp[2][1001][31], result = 0;
int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, w;
    cin >> t >> w;

    for (int i = 1; i <= t; i++)
        cin >> arr[i];

    for (int i = 1; i <= t; i++)
    {
        dp[0][i][0] = dp[0][i - 1][0] + (arr[i] == 1);
        for (int j = 1; j <= w; j++)
        {
            dp[0][i][j] = max(dp[0][i - 1][j], dp[1][i - 1][j - 1]) + (arr[i] == 1);
            dp[1][i][j] = max(dp[1][i - 1][j], dp[0][i - 1][j - 1]) + (arr[i] == 2);
        }
    }
    for (int j = 0; j <= w; j++)
    {
        result = max(result, max(dp[1][t][j], dp[0][t][j]));
    }
    cout << result;
}