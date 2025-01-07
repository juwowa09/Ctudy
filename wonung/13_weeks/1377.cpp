#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v[i] = {k, i};
    }

    int result = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        result = max(result, v[i].second - i);
    cout << result + 1;
}