#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];
int visit[8];
int result[8];

void dfs(int d, int m, int n)
{
    if (d == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0 && tmp != arr[i])
        {
            visit[i] = 1;
            tmp = arr[i];
            result[d] = arr[i];
            dfs(d + 1, m, n);
            visit[i] = 0;
        }
    }
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
    dfs(0, m, n);
}