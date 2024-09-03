#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0, cnt;
    double llean, rlean;

    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        llean = 1000000000;
        rlean = -1000000000;
        for (int j = i - 1; j >= 0; j--)
        {
            if (llean > (double)(arr[i] - arr[j]) / (i - j))
            {
                cnt++;
                llean = (double)(arr[i] - arr[j]) / (i - j);
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (rlean < (double)(arr[j] - arr[i]) / (j - i))
            {
                cnt++;
                rlean = (double)(arr[j] - arr[i]) / (j - i);
            }
        }
        if (cnt > result)
            result = cnt;
    }
    cout << result;
}