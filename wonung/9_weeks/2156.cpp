#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int arr[10003];
    int dp[10003];
    cin >> n;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    arr[2] = 0;
    for (int i = 3; i < n + 3; i++)
    {
        cin >> arr[i];
        dp[i] = max(max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i], dp[i - 1]);
    }

    cout << dp[n + 2];
}