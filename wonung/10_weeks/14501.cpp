#include <iostream>
using namespace std;

int dp[21] = {
    0,
};
int T[16];
int P[16];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    for (int i = 1; i < n + 1; i++)
        cin >> T[i] >> P[i];

    for (int i = 1; i <= n + 1; i++)
    {
        dp[i] = dp[i] < dp[i - 1] ? dp[i - 1] : dp[i];
        dp[i + T[i]] = dp[i + T[i]] < dp[i] + P[i] ? dp[i] + P[i] : dp[i + T[i]];
    }
    cout << dp[n + 1];
}