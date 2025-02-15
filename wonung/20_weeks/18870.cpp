#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v[i] = arr[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++)
        cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << " ";
}