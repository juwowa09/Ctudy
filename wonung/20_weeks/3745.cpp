#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    while (cin >> n)
    {
        arr.clear();
        arr.resize(n);
        v.clear();

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            if (v.empty())
                v.push_back(arr[i]);
            else
            {
                int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
                if (pos == v.size())
                    v.push_back(arr[i]);
                else
                    v[pos] = arr[i];
            }
        }
        cout << v.size() << "\n";
    }
}