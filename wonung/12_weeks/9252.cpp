#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s1, s2;
    stack<char> s;
    string str1;
    string str2;

    cin >> str1 >> str2;

    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1] < dp[i - 1][j] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    s1 = str1.size();
    s2 = str2.size();
    cout << dp[s1][s2] << "\n";
    while (dp[s1][s2] != 0)
    {
        if (dp[s1 - 1][s2] == dp[s1][s2 - 1] && dp[s1][s2] != dp[s1 - 1][s2])
        {
            s.push(str2[s2 - 1]);
            s1--;
            s2--;
        }
        else if (dp[s1 - 1][s2] > dp[s1][s2 - 1])
            s1--;
        else
            s2--;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}