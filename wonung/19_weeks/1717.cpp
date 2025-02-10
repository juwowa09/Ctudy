#include <iostream>
using namespace std;

int n, m;
int group[1000001];

int find_g(int x)
{
    if (group[x] >= 0)
        return group[x] = find_g(group[x]);
    return x;
}

void merge(int x, int y)
{
    int g_x = find_g(x);
    int g_y = find_g(y);

    if (g_x != g_y)
    {
        if (group[g_x] < group[g_y])
        {
            group[g_x] += group[g_y];
            group[g_y] = g_x;
        }
        else if (group[g_x] > group[g_y])
        {
            group[g_y] += group[g_x];
            group[g_x] = g_y;
        }
        else
        {
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        group[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        switch (op)
        {
        case 0:
            merge(a, b);
            break;
        case 1:
            if (find_g(a) == find_g(b))
                cout << "YES\n";
            else
                cout << "NO\n";
            break;
        }
    }
}