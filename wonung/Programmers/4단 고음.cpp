#include <cmath>

int result;

// 뒤에서부터 줄여나가는 dfs, num = 현재 계산된 수, cnt = 현재 표현된 수의 + 개수
void dfs(int num, int cnt)
{
    // num 이 3보다 작으면 표현 불가능 수, 현재 존재하는 (*++) 쌍에서 + 개수가 2개면 *가 하나.
    // ** -> + 4개 필요. == 9보다 큰 수. 9보다 작으면 표현불가능 수 임.
    if (num < 3 || pow(3, cnt / 2) > num)
        return;

    if (num == 3)
    {
        if (cnt == 2) // * 한개 ++ 두개 수가 맞아야 함.
            result++;
        return;
    }

    if (num % 3 == 0 && cnt >= 2)
        dfs(num / 3, cnt - 2); // *표현 하면서 ++ 삭제.

    dfs(num - 1, cnt + 1); // + 표현
}

int solution(int n)
{
    int answer = 0;

    dfs(n, 0);
    return result;
}