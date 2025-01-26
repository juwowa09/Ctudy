#include <string>
#include <vector>

using namespace std;

int num, result = 0;

int dp[15];

int solution(int n)
{
    int answer = 0;
    num = 2 * n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];

    answer = dp[n];
    return answer;
}