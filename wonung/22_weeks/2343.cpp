#include <iostream>
using namespace std;

int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, num = 0, mx = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    int st = mx, en = 1e9;

    while (st < en)
    {
        int mid = st + (en - st) / 2;
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                cnt++;
                sum = arr[i];
            }
        }
        if (cnt > m)
            st = mid + 1;
        else
            en = mid;
    }
    cout << en;
}