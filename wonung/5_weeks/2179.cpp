#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, maxlen = 0;
    vector<string> v;
    string sub;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 100; i >= 1; i--)
    {
        map<string, vector<int>> m;
        pair<int, int> ans = {1e9, 1e9};
        for (int j = 0; j < n; j++)
        {
            if (v[j].size() < i)
                continue;
            sub = v[j].substr(0, i);
            if (m.count(sub))
                ans = min(ans, {m[sub][0], j});
            m[sub].push_back(j);
        }
        // 앞 순서부터 차례대로 확인
        auto [x, y] = ans;
        if (x < 1e9)
        {
            cout << v[x] << '\n'
                 << v[y];
            return 0;
        }
    }
    cout << v[0] << '\n'
         << v[1];
}