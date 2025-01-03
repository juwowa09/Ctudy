#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
int dpmax[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int curmax, result = 0, n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dpmax[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                dpmax[i] = max(dpmax[i], dpmax[j] + arr[i]);
        }
        result = max(dpmax[i], result);
    }
    cout << result;
}