#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int *arr = new int[n + 3];
    int *dp = new int[n + 3];

    for (int i = 0; i < 3; i++)
        dp[i] = 0;

    arr[2] = 0;
    for (int i = 3; i < n + 3; i++)
    {
        cin >> arr[i];
        dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
    }
    cout << dp[n + 2];
    delete[] dp;
}