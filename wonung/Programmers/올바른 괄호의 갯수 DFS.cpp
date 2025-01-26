#include <string>
#include <vector>

using namespace std;

int num, result = 0;

void dfs(int n, int value)
{
    if (value < 0)
        return;
    if (n == num)
    {
        if (value == 0)
            result++;
        return;
    }
    dfs(n + 1, value + 1);
    dfs(n + 1, value - 1);
}

int solution(int n)
{
    int answer = 0;
    num = 2 * n;
    dfs(0, 0);
    answer = result;
    return answer;
}