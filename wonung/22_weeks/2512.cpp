#include <iostream>
using namespace std;

int n, m, s, up;
int arr[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        up = max(up, arr[i]);
        s += arr[i];
    }

    cin >> m;
    int st = 1;
    int en = 100001;

    if (s <= m)
    {
        cout << up;
        return 0;
    }
    while (st <= en)
    {
        int mid = st + (en - st) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid >= arr[i])
                sum += arr[i];
            if (mid < arr[i])
                sum += mid;
        }
        if (sum > m)
            en = mid - 1;
        else
            st = mid + 1;
    }
    cout << en;
}