#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, cnt = 0;
    string name;
    set<string> s;
    set<string> nvh;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        s.insert(name);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> name;
        if (s.find(name) != s.end())
            nvh.insert(name);
    }
    cout << nvh.size() << '\n';
    for (set<string>::iterator it = nvh.begin(); it != nvh.end(); it++)
    {
        cout << *it << '\n';
    }
}