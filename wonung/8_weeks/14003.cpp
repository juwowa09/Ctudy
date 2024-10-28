#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int lower(int *arr, int s, int e, int value)
{
    if (s >= e)
        return s;
    int m = (s + e) / 2;
    if (value <= arr[m])
        return lower(arr, s, m, value);
    else
        return lower(arr, m + 1, e, value);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, cnt = 0, num;

    cin >> n;
    vector<pair<int, int>> arr;
    stack<int> s;
    int *lis = new int[n];

    arr.resize(n);
    for (int i = 0; i < n; i++)
        lis[i] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int pos = lower(lis, 0, cnt, num);
        if (cnt == pos)
            cnt++;
        lis[pos] = num;
        arr[i].first = num;
        arr[i].second = pos;
    }

    cout << cnt << '\n';
    cnt--;
    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt == arr[i].second)
        {
            s.push(arr[i].first);
            cnt--;
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    delete[] lis;
}