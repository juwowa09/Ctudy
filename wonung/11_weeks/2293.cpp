#include <iostream>
using namespace std;

int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, w;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        for (int j = w; j <= k; j++)
            dp[j] = dp[j] + dp[j - w];
    }
    cout << dp[k];
}