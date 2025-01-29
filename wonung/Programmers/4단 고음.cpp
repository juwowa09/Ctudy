#include <cmath>

int result;

void dfs(int num, int cnt)
{
    if (num < 3 || pow(3, cnt / 2) > num)
        return;

    if (num == 3)
    {
        if (cnt == 2)
            result++;
        return;
    }

    if (num % 3 == 0 && cnt >= 2)
        dfs(num / 3, cnt - 2);

    dfs(num - 1, cnt + 1);
}

int solution(int n)
{
    int answer = 0;

    dfs(n - 2, 2);
    return result;
}