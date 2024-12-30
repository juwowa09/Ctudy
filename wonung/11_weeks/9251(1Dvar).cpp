#include <iostream>
using namespace std;

int dp[1001];

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
        int prev = 0; // 항상 첫 col 에 대해서는 0으로 prev 를 시작
        for (int j = 1; j <= s2.size(); j++)
        {
            int tmp = dp[j];            // 잠시 저장해둘 이전 값(dp[i-1][j-1])
            if (s1[i - 1] == s2[j - 1]) // 여기서 dp[j] 값이 바뀔수도 있음(j+1 에서 사용하기 위함)
                dp[j] = prev + 1;       // dp[i-1][j-1] + 1
            else
                dp[j] = dp[j - 1] < dp[j] ? dp[j] : dp[j - 1];
            prev = tmp; // j+1 에서 사용할 prev
        }
    }
    cout << dp[s2.size()];
}