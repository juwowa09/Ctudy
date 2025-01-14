#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, v;
    cin >> n >> k;

    vector<int> dp(10001, 10001);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        for (int j = 0; v <= k && j <= k - v; j++)
            dp[j + v] = min(dp[j] + 1, dp[j + v]);
    }
    if (dp[k] > 10000)
        cout << -1;
    else
        cout << dp[k];
}