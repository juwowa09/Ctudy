#include <iostream>
#define MAX 1000000000
using namespace std;

long long x, y, z;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;
    z = y * 100 / x;

    if (z >= 99)
        cout << -1;
    else
    {
        int left = 0, right = MAX;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int tmp = (y + mid) * 100 / (x + mid);

            if (z < tmp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout << left;
    }
}