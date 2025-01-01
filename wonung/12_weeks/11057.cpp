#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> dp(10, 1);
    vector<int> prev(10, 1);
    cin >> n;
    while (n--)
    {
        dp[9] = prev[9];
        for (int j = 8; j >= 0; j--)
            dp[j] = (prev[j] + dp[j + 1]) % 10007;
        prev = dp;
    }
    cout << dp[0];
}