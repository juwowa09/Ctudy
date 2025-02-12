#include <iostream>
#include <vector>
#define MAX 18
using namespace std;

int n, m;
int level[100001];
int parent[100001][MAX];
vector<int> adj[100001];

int LCA(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;

    if (level[a] < level[b])
        swap(a, b);

    if (level[a] != level[b])
    {
        for (int i = MAX - 1; i >= 0; i--)
            if (level[parent[a][i]] >= level[b])
                a = parent[a][i];
    }
    if (a == b)
        return a;
    int result;
    for (int i = MAX - 1; i >= 0; i--)
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

void setTree(int c, int p)
{
    parent[c][0] = p;
    level[c] = level[p] + 1;

    for (int i = 1; i < MAX; i++)
        parent[c][i] = parent[parent[c][i - 1]][i - 1];

    for (auto it : adj[c])
        if (it != p)
            setTree(it, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    setTree(1, 0);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}