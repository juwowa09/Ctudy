#include <iostream>
#include <math.h>
using namespace std;

int arr[9][9];

bool isSquare(int n)
{
    int t = sqrt(n);
    return t * t == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = -1;
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - 48;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = -n; k <= n; k++)
            {
                for (int t = -m; t <= m; t++)
                {
                    if (k == 0 && t == 0)
                    {
                        continue;
                    }
                    int tmp = 0, g = i, h = j;
                    while (g < n && g >= 0 && h < m && h >= 0)
                    {
                        tmp = tmp * 10 + arr[g][h];
                        g += k;
                        h += t;
                        if (isSquare(tmp))
                            result = result < tmp ? tmp : result;
                    }
                }
            }
        }
    }
    cout << result;
}