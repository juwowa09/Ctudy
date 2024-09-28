#include <iostream>
#include <vector>
using namespace std;

int rFind(int x, int *arr)
{
    if (arr[x] != x)
        return arr[x] = rFind(arr[x], arr);
    return arr[x];
}

void merge(int x, int y, int *arr)
{
    int rx = rFind(x, arr);
    int ry = rFind(y, arr);

    if (rx != ry)
    {
        if (rx < ry)
            arr[ry] = rx;
        else
            arr[rx] = ry;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    vector<int> v;
    cin >> n >> m;
    int *arr = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
        arr[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> t;
            if (t == 1)
                merge(i, j, arr);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        if (!v.empty() && rFind(v.front(), arr) != rFind(t, arr))
        {
            cout << "NO";
            return 0;
        }
        v.push_back(t);
    }
    cout << "YES";
    delete[] arr;
}