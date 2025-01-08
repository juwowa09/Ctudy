#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mx(int a, int b, int c)
{
    return max(max(a, b), c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str1;
    string str2;
    string str3;
    cin >> str1 >> str2 >> str3;

    vector<vector<int>> dp(str2.size() + 1, vector<int>(str3.size() + 1, 0));
    vector<vector<int>> prev(str2.size() + 1, vector<int>(str3.size() + 1, 0));
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            for (int k = 1; k <= str3.size(); k++)
            {
                if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
                    dp[j][k] = prev[j - 1][k - 1] + 1;
                else
                    dp[j][k] = mx(dp[j][k - 1], dp[j - 1][k], prev[j][k]);
            }
        }
        prev = dp;
    }
    cout << dp[str2.size()][str3.size()];
}