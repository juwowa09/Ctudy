#include <iostream>
using namespace std;

int dp[1001];
int pre[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1;
    string s2;
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[j] = pre[j - 1] + 1;
            else
                dp[j] = dp[j - 1] < pre[j] ? pre[j] : dp[j - 1];
        }
        for (int j = 1; j <= s2.size(); j++)
            pre[j] = dp[j];
    }
    cout << dp[s2.size()];
}