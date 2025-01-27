#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result = 0x7FFFFFFF;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int k, s = 0, e = n - 1, first, second;

    while (n--)
    {
        cin >> k;
        arr.push_back(k);
    }

    sort(arr.begin(), arr.end());

    while (s < e)
    {
        if (abs(arr[s] + arr[e]) < result)
        {
            result = abs(arr[s] + arr[e]);
            first = s;
            second = e;
        }
        if (arr[s] + arr[e] == 0)
        {
            cout << arr[s] << " " << arr[e];
            return 0;
        }
        else if (arr[s] + arr[e] > 0)
            e--;
        else
            s++;
    }
    cout << arr[first] << " " << arr[second];
}