#include <iostream>
#include <algorithm>
using namespace std;

int n, c, result;
int arr[200000];
int dist[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int st = 1;
    int en = 1000000001;

    while (st < en)
    {
        int mid = st + (en - st) / 2;
        int cnt = 1;
        dist[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            int d = arr[i] - dist[cnt - 1];
            if (mid <= d)
            {
                dist[cnt] = arr[i];
                cnt++;
                if (cnt == c)
                    break;
            }
        }
        if (cnt == c)
        {
            st = mid + 1;
            result = max(result, mid);
        }
        else
            en = mid;
    }
    cout << result;
}