#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    vector<int> v;
    vector<int> pos(n, 0);
    vector<int> arr(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (v.empty())
            v.push_back(arr[i]);
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), arr[i]);
        pos[i] = it - v.begin();
        if (it == v.end())
            v.push_back(arr[i]);
        else
            *it = arr[i];
    }
    cout << v.size() << "\n";

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (pos[n - 1] != i)
            n--;
        s.push(arr[n - 1]);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}