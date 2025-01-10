#include <iostream>
using namespace std;

int dp[1001][3];
int arr[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 1000000;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == j)
                dp[1][i] = arr[1][i];
            else
                dp[1][i] = 1000000;
        }

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = arr[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == j)
                continue;
            result = min(result, dp[n][i]);
        }
    }
    cout << result;
}