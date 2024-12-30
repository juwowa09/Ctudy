#include <iostream>
#include <cstring>
using namespace std;

int dp[31][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, west, east;
    cin >> n;
    for (int t = 0; t < n; t++)
    {
        cin >> west >> east;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= east; i++)
            dp[1][i] = i;

        for (int i = 2; i <= west; i++)
        {
            for (int j = i; j <= east; j++)
            {
                for (int k = j; k >= i; k--)
                {
                    dp[i][j] = dp[i][j] + dp[i - 1][k - 1];
                }
            }
        }
        cout << dp[west][east] << "\n";
    }
}