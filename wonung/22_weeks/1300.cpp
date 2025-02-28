#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> n >> k;

    int st = 1;
    int en = k; // 정렬 시 k 번째에 있는 수는 반드시 k보다 작으므로 상한선을 k 로 둬도 됨

    while (st < en)
    {
        int mid = st + (en - st) / 2;
        int sum = 0;

        // 행렬에서 행을 오름차순으로 k 보다 작은 수의 개수 세기
        for (int i = 1; i <= n; i++)
            sum += min(n, mid / i); // 최대 n개의 열이 있다
        // 해당 열은 행의 배수로 이루어져 있으므로 mid/i 개 가 있을 수 있음

        if (sum >= k)
            en = mid;
        else
        {
            st = mid + 1;
        }
    }
    cout << en;
}