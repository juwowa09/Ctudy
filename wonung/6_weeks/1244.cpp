#include <iostream>
using namespace std;

void solv(int *arr, int l, int s, int num)
{
    if (s == 1)
    {
        for (int i = 1; i * num <= l; i++)
        {
            if (arr[i * num] == 0)
                arr[i * num] = 1;
            else
                arr[i * num] = 0;
        }
    }
    else
    {
        if (arr[num] == 0)
            arr[num] = 1;
        else
            arr[num] = 0;
        for (int i = 1; num + i <= l && num - i >= 1; i++)
        {
            if (arr[num + i] == arr[num - i])
            {
                if (arr[num + i] == 0)
                {
                    arr[num + i] = 1;
                    arr[num - i] = 1;
                }
                else
                {
                    arr[num + i] = 0;
                    arr[num - i] = 0;
                }
            }
            else
                break;
        }
    }
}

int main()
{
    int n, m, s, num;
    int *arr;
    cin >> n;
    arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        cin >> num;
        solv(arr, n, s, num);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
        if (i % 20 == 0)
            cout << '\n';
    }
    delete[] arr;
}