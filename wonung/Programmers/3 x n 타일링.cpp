#include <string>
#include <vector>

using namespace std;

long dp[5001];

int solution(int n)
{
    int answer = 0;
    dp[2] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (i % 2 == 1)
            continue;

        dp[i] = (dp[i - 2] * 3 + 2) % 1000000007;

        for (int j = i - 4; j > 0; j -= 2)
            dp[i] = (dp[i] + dp[j] * 2) % 1000000007;
    }
    answer = dp[n];
    return answer;
}