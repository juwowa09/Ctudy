#include <iostream>
using namespace std;

long dp[31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j > 0; j--)
            dp[i] += dp[j] * 2;
        dp[i] += 2;
    }
    cout << dp[n];
}