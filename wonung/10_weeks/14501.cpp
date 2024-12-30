#include <iostream>
using namespace std;

int dp[21] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, t, p;

    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> t >> p;
        dp[i] = dp[i] < dp[i - 1] ? dp[i - 1] : dp[i];
        dp[i + t] = dp[i + t] < dp[i] + p ? dp[i] + p : dp[i + t];
    }
    dp[n + 1] = dp[n + 1] < dp[n] ? dp[n] : dp[n + 1];
    cout << dp[n + 1];
}