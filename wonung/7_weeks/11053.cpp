#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, result = 1;

    cin >> n;
    int *arr = new int[n];
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                if (result < dp[i])
                    result = dp[i];
            }
        }
    }
    cout << result;
    delete[] arr;
    delete[] dp;
}