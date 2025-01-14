#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result = 0;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        arr[i] += arr[i - 1];
        result += arr[i];
    }
    cout << result;
}