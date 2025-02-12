#include <iostream>
#include <math.h>
using namespace std;

int n, m;
int group[100001];
int arr[100001];

int find_g(int x)
{
    if (x != group[x])
    {
        int p = find_g(group[x]);
        arr[x] += arr[group[x]];
        return group[x] = p;
    }
    return x;
}

void merge(int x, int y, int w)
{
    int g_x = find_g(x);
    int g_y = find_g(y);

    if (g_x != g_y)
    {
        arr[g_y] = arr[x] - arr[y] + w;
        group[g_y] = g_x;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char q;
    while (1)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            arr[i] = 0;
            group[i] = i;
        }
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> q >> a >> b;

            switch (q)
            {
            case '!':
                cin >> c;
                merge(a, b, c);
                break;
            case '?':
                if (find_g(a) != find_g(b))
                    cout << "UNKNOWN\n";
                else
                    cout << arr[b] - arr[a] << "\n";
                break;
            }
        }
    }
}