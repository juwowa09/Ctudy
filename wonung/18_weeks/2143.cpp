#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long t, n, m, result = 0;
vector<int> arr1, arr2, arr3, arr4;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr1.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        arr3.push_back(arr1[i]);
        int sum = arr1[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += arr1[j];
            arr3.push_back(sum);
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> num;
        arr2.push_back(num);
    }

    for (int i = 0; i < m; i++)
    {
        arr4.push_back(arr2[i]);
        int sum = arr2[i];
        for (int j = i + 1; j < m; j++)
        {
            sum += arr2[j];
            arr4.push_back(sum);
        }
    }
    sort(arr4.begin(), arr4.end());

    for (int i = 0; i < arr3.size(); i++)
    {
        int n = upper_bound(arr4.begin(), arr4.end(), t - arr3[i]) - lower_bound(arr4.begin(), arr4.end(), t - arr3[i]);
        result += n;
    }
    cout << result;
}