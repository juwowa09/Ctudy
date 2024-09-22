#include <iostream>
using namespace std;

int display[10][10] = {
    {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0},
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, k, p, result = 0;
    cin >> n >> k >> p >> x;

    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        int temp1 = x;
        int temp2 = i;
        int pos = p;
        for (int j = 0; j < k; j++)
        {
            pos -= display[temp1 % 10][temp2 % 10];
            temp1 /= 10;
            temp2 /= 10;
        }

        if (pos >= 0)
            result++;
    }
    cout << result;
}