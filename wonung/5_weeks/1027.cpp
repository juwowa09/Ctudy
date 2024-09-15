#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    double lean;

    cin >> n;

    int *arr = new int[n];
    int *cnt = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        lean = -1000000000;
        for (int j = i + 1; j < n; j++)
        {
            if (lean < (double)(arr[j] - arr[i]) / (j - i))
            {
                cnt[i]++;
                cnt[j]++;
                lean = (double)(arr[j] - arr[i]) / (j - i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (result < cnt[i])
            result = cnt[i];
    }
    cout << result;
    delete[] cnt;
    delete[] arr;
}