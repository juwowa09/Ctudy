#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;
    int *arr = new int[n];
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[j] >= dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > result)
            result = dp[i];
    }
    cout << n - result;
}