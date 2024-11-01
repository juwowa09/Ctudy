#include <iostream>
#include <algorithm>
using namespace std;

long long power(int a, int b, int c)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % c;

    long long k = power(a, b / 2, c);
    if (b % 2 == 0)
        return (k * k) % c;
    else
        return (((k * k) % c) * (a % c)) % c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    cout << power(a, b, c);
}