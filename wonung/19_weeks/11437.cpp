#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[100001];
int level[100001];
vector<int> adj[100001];

int LCA(int a, int b)
{
    while (level[a] < level[b])
        b = parent[b];
    while (level[a] > level[b])
        a = parent[a];

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void setTree(int c, int p)
{
    parent[c] = p;
    level[c] = level[p] + 1;

    for (auto it : adj[c])
    {
        if (it == p)
            continue;
        setTree(it, c);
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
    setTree(1, 0);

    cin >> m;

    while (m--)
    {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
        ;
    }
}