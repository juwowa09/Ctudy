#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<int> v;
vector<int> vis;

int sol(int first, int curr, set<int> *s)
{
    if (vis[curr] == 1 && first == curr)
    {
        return 1;
    }
    else if (vis[curr])
        return 0;
    else
    {
        vis[curr] = 1;
        if (sol(first, v[curr], s) == 1)
        {
            s->insert(curr);
            vis[curr] = 0;
            return 1;
        }
        vis[curr] = 0;
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    set<int> s;
    cin >> n;
    v.push_back(0);
    vis.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        v.push_back(k);
        vis.push_back(0);
    }
    for (int i = 1; i <= n; i++)
    {
        sol(i, i, &s);
    }
    cout << s.size() << '\n';
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << '\n';
}