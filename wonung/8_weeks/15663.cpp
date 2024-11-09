#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];
int visit[8];
int result[8];

void dfs(int tmp, int d, int m, int n, int idx)
{
    if (idx == n)
        return;
    if (d == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (visit[idx] == 0 && tmp != arr[idx])
    {
        visit[idx] = 1;
        result[d] = arr[idx];
        tmp = arr[idx];         // tmp = 중복방지 수
        dfs(0, d + 1, m, n, 0); // 조건만족, 다음 수 찾기
        visit[idx] = 0;
    }
    dfs(tmp, d, m, n, idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        visit[i] = 0;
        result[i] = 0;
    }

    sort(arr, arr + n);
    dfs(0, 0, m, n, 0);
}