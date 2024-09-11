#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d, k, c, num, max = 0;
    vector<int> v;

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    unordered_map<int, int> m;
    for (int j = 0; j < k; j++)
    {
        m[v[j]]++;
    }
    for (int i = 0; i < n; i++)
    {
        m[v[i]]--;
        if (m[v[i]] == 0)
            m.erase(v[i]);
        m[v[(i + k) % n]]++;
        m[c]++;
        if (m.size() > max)
            max = m.size();
        m[c]--;
        if (m[c] == 0)
            m.erase(c);
    }
    cout << max;
}
