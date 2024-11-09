#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int a, int b)
{
    return a < b;
}

int lower_search(int *arr, int s, int e, int value)
{
    if (s >= e)
        return s;
    int m = (s + e) / 2;
    if (arr[m] >= value)
        return lower_search(arr, s, m, value);
    else
        return lower_search(arr, m + 1, e, value);
}

int upper_search(int *arr, int s, int e, int value)
{
    if (s >= e)
        return s;
    int m = (s + e) / 2;
    if (arr[m] <= value)
        return upper_search(arr, m + 1, e, value);
    else
        return upper_search(arr, s, m, value);
}

int bs(int *arr, int s, int e, int value)
{
    if (s >= e)
        return 0;

    int m = (s + e) / 2;

    if (arr[m] == value)
        return 1;
    else if (value > arr[m])
        return bs(arr, m + 1, e, value);
    else
        return bs(arr, s, m, value);
}

int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, cmp);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        cout << bs(arr, 0, n, num) << '\n';
    }
}