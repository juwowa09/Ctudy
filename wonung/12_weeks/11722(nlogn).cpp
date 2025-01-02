#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, result;
    cin >> n;
    vector<int> v(n, 0);
    stack<int> s;
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        s.push(k);
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = s.top();
        s.pop();
        if (dp.empty())
            dp.push_back(v[i]);
        auto it = lower_bound(dp.begin(), dp.end(), v[i]);
        int pos = it - dp.begin();
        if (it == dp.end())
            dp.push_back(v[i]);
        else
            *it = v[i];
    }
    cout << dp.size();
}