#include <iostream>

using namespace std;

int dp[31][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;

        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        cout << dp[k][n] << "\n";
    }
}