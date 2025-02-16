#include <iostream>
#include <queue>
#define MAX 1000000000
using namespace std;

int n, m, w;
int dist[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = MAX;
            if (i == j)
                dist[i][j] = 0;
        }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dist[i][j] == MAX ? cout << 0 << " " : cout << dist[i][j] << " ";
        cout << "\n";
    }
}