#include <iostream>
#include <algorithm>
using namespace std;

int n, m, result = 0;
long sum;
int arr[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    int en = arr[n - 1];
    int st = 0;

    while (st < en)
    {
        sum = 0;
        int mid = st + (en - st) / 2;

        for (int i = 0; i < n; i++)
            if (arr[i] > mid)
                sum += arr[i] - mid;

        if (sum >= m)
        {
            result = max(result, mid);
            st = mid + 1;
        }
        else
            en = mid;
    }
    cout << result;
}