#include <iostream>
#define Div 1000000007
using namespace std;

int n, k;

long long fast(int a, int b)
{
    if (b == 0)
        return 1;
    long long k = fast(a, b / 2) % Div;

    if (b % 2)
        return a * (k * k % Div) % Div;
    else
        return k * k % Div;
}

long long sol()
{
    if (n == k || k == 0)
        return 1;
    else if (k == 1 || n - k == 1)
        return n;

    long long a = 1, b = 1;
    for (int i = n; i >= n - k + 1; i--)
        a = (a * i) % Div;
    for (int i = 1; i <= k; i++)
        b = (b * i) % Div;

    return (a % Div * (fast(b, Div - 2) % Div)) % Div;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cout << sol();
}