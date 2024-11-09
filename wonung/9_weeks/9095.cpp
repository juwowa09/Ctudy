#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int dp[14];

    cin >> t;
    dp[0] = 1; //   기본 1, 2, 3 도 하나로 취급
    dp[1] = 1;
    dp[2] = 2;
    while (t--)
    {
        cin >> n;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        cout << dp[n] << '\n';
    }
}