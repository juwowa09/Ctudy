#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;
    vector<int> v;
    stack<int> s;
    vector<int> arr(n, 0);
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.push(arr[i]);
        if (v.empty())
            v.push_back(arr[i]);
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        int pos = it - v.begin() + 1;
        if (v.end() == it)
            v.push_back(arr[i]);
        else
            *it = arr[i];
        p[i] = pos;
    }
    v.clear();
    for (int i = 0; i < n; i++)
    {
        arr[i] = s.top();
        s.pop();
        if (v.empty())
            v.push_back(arr[i]);
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        int pos = it - v.begin() + 1;
        if (v.end() == it)
            v.push_back(arr[i]);
        else
            *it = arr[i];
        result = max(result, p[n - i - 1] + pos - 1);
    }
    cout << result;
}