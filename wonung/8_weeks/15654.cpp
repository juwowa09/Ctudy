#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];
int vis[8];
int result[8];

void back_track(int depth, int n, int m)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            result[depth] = arr[i];
            vis[i] = 1;
            back_track(depth + 1, n, m);
            vis[i] = 0;
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
        vis[i] = 0;
    }
    sort(arr, arr + n);
    back_track(0, n, m);
}