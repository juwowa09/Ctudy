#include <iostream>
#include <vector>
#include <set>

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
    set<int> s;
    for (int j = 0; j < k; j++)
    {
        s.insert(v[j]);
    }
    s.insert(c);
    for (int i = 0; i < n; i++)
    {
        s.erase(v[i]);
        s.insert(v[(i + k) % n]);
        s.insert(c);
        if (s.size() > max)
            max = s.size();
    }
    cout << max;
}