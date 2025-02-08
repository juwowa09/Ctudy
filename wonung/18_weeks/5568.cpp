#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n, k;
set<string> s;
vector<string> v;
bool visited[10];

void dfs(int cur, int cnt, string str)
{
    if (visited[cur])
    {
        dfs(cur + 1, cnt, str);
        return;
    }
    if (cnt == k)
    {
        s.insert(str);
        return;
    }
    if (cur == n)
        return;

    visited[cur] = true;
    string s = str + v[cur];
    dfs(0, cnt + 1, s);
    visited[cur] = false;
    dfs(cur + 1, cnt, str);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dfs(0, 0, "");
    cout << s.size();
}