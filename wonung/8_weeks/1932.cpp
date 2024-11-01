#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num, result = 0;
    int dp[501][500];
    dp[0][0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> num;
            if (j == 0)
                dp[i][j] = num + dp[i - 1][j];
            else if (j == i - 1)
                dp[i][j] = num + dp[i - 1][j - 1];
            else
                dp[i][j] = num + max(dp[i - 1][j], dp[i - 1][j - 1]);
            if (i == n && result < dp[i][j])
            {
                result = dp[i][j];
            }
        }
    }
    cout << result;
}