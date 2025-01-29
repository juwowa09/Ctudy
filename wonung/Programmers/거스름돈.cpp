#include <string>
#include <vector>

using namespace std;
int dp[100001];

int solution(int n, vector<int> money)
{
    int answer = 0;
    dp[0] = 1;
    for (int j = 0; j < money.size(); j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (money[j] <= i)
                dp[i] = (dp[i] + (dp[i - money[j]])) % 1000000007;
        }
    }
    answer = dp[n];
    return answer;
}