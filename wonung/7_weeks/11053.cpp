#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int *arr = new int[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if (it == v.end())
        {
            v.push_back(arr[i]);
        }
        else
            *it = arr[i];
    }
    cout << v.size();
}