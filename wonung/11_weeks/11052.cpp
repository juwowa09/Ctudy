#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int *dp;

    cin >> n;
    dp = new int[n + 1];
    cin >> dp[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> dp[i];
        for (int j = 1; j <= i / 2; j++)
            dp[i] = max(dp[j] + dp[i - j], dp[i]);
    }
    cout << dp[n];
    delete[] dp;
}