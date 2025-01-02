#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result;
    cin >> n;
    vector<int> v(n, 0);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = i - 1; j >= 0; j--)
            if (v[j] > v[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;

        result = max(result, dp[i]);
    }
    cout << result;
}