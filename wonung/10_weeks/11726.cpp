#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, result;
    int *dp;

    cin >> n;
    dp = new int[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % 10007;
    }
    cout << dp[n - 1];
    delete[] dp;
}