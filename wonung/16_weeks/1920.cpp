#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int arr[100000];

int binary_s(int st, int en, int v)
{
    if (st == en)
        return 0;

    int mid = st + (en - st) / 2;

    if (arr[mid] == v)
        return 1;
    if (arr[mid] > v)
        return binary_s(st, mid, v);
    else
        return binary_s(mid + 1, en, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    cin >> m;

    while (m--)
    {
        cin >> k;
        cout << binary_s(0, n, k) << "\n";
    }
}