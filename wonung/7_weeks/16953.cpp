#include <iostream>
using namespace std;

int recur(int a, int b, int cnt)
{
    if (a == b)
        return cnt;
    else if (a > b)
        return -1;

    if (b % 10 == 1)
        return recur(a, b / 10, cnt + 1);
    else if (b % 2 == 0)
        return recur(a, b / 2, cnt + 1);
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> a >> b;
    cout << recur(a, b, 1);
}