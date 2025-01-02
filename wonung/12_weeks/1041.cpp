#include <iostream>
#include <algorithm>
using namespace std;

int dice[6];
int num[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long result = 0;
    int m = 0;

    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
        result += dice[i];
        m = max(m, dice[i]);
    }
    if (n == 1)
    {
        cout << result - m;
        return 0;
    }
    result = 0;
    num[0] = min(dice[0], dice[5]);
    num[1] = min(dice[1], dice[4]);
    num[2] = min(dice[2], dice[3]);
    sort(num, num + 3);

    result = result + (n - 2) * (n - 2) * num[0] * 5 + (n - 2) * num[0] * 4;
    result = result + 4 * (num[0] + num[1] + num[2]);
    result = result + (n - 1) * (num[0] + num[1]) * 4 + (n - 2) * (num[0] + num[1]) * 4;
    cout << result;
}