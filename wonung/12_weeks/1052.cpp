#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, result = -1, cnt = 0;

    cin >> n >> k;
    while (k)
    {
        int tmp = n;
        int c = k;
        while (tmp)
        {
            if (tmp % 2 == 1)
                c--;
            tmp /= 2;
            if (c == 0 && tmp > 0)
            {
                n++;
                cnt++;
                break;
            }
        }
        if (c || (c == 0 && tmp == 0))
            break;
    }
    cout << cnt;
}