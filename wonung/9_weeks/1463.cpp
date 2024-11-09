#include <iostream>
using namespace std;

void sol(int num, int *arr)
{
    int min = 10000000;
    if (num == 1)
    {
        arr[num] = 0;
        return;
    }
    if (num % 3 == 0)
    {
        min = 1 + arr[num / 3];
    }
    if (num % 2 == 0 && min > arr[num / 2] + 1)
    {
        min = 1 + arr[num / 2];
    }
    if (min > arr[num - 1] + 1)
    {
        min = 1 + arr[num - 1];
    }
    arr[num] = min;
}

int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sol(i, arr);
    }
    cout << arr[n];
}