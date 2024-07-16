#include <iostream>
#include <queue>
using namespace std;

int a[1000001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, x, g, max = 0, sum = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> g >> x;
        a[x] = g;
    }
    for (int i = 1; i <= 2 * k + 1; i++)
    {
        sum += a[i];
    }
    max = sum;
    for (int i = k + 2; i <= 1000000 - k; i++)
    {
        sum = sum - a[i - k - 1] + a[i + k];
        if (sum > max)
            max = sum;
    }
    cout << max;
}