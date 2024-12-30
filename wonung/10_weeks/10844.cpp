#include <iostream>
using namespace std;

int dp[101][10] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            switch (j)
            {
            case 0:
                dp[i][j] = dp[i - 1][1];
                break;
            case 9:
                dp[i][j] = dp[i - 1][8];
                break;
            default:
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }
    for (int i = 1; i < 10; i++)
    {
        result = (result + dp[n][i]) % 1000000000;
    }
    cout << result;
}