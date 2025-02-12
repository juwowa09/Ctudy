#include <iostream>
#include <vector>
using namespace std;

int n, m;
int adj[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 999999999;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int result = 0;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (adj[i][j] != 999999999 || adj[j][i] != 999999999)
                cnt++;
        if (cnt == n - 1)
            result++;
    }
    cout << result;
}