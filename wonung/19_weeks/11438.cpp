#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, maxlevel;
int parent[100001][18];
int level[100001];
vector<int> adj[100001];

int LCA(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;

    if (level[a] < level[b])
    {
        int t = a;
        a = b;
        b = t;
    }

    if (level[a] != level[b])
    {
        for (int i = maxlevel; i >= 0; i--)
        {
            if (level[parent[a][i]] >= level[b])
                a = parent[a][i];
        }
    }

    if (a == b)
        return a;

    int result;
    for (int i = maxlevel; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
        result = parent[a][i];
    }

    return result;
}

void setTree(int c, int p, int l)
{
    parent[c][0] = p;
    level[c] = l;

    for (int i = 1; i <= maxlevel; i++)
        parent[c][i] = parent[parent[c][i - 1]][i - 1];

    for (auto it : adj[c])
    {
        if (it == p)
            continue;
        setTree(it, c, l + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maxlevel = (int)floor(log2(100001));
    setTree(1, 0, 1);

    cin >> m;

    while (m--)
    {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
        ;
    }
}