#include <iostream>
#include <vector>
#define MAX 18
using namespace std;

int n, m;
int parent[100001][MAX];
int level[100001];
vector<int> adj[100001];

int LCA(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;

    if (level[a] != level[b])
    {
        if (level[a] < level[b])
            swap(a, b);

        for (int i = MAX - 1; i >= 0; i--)
        {
            if (level[parent[a][i]] >= level[b])
                a = parent[a][i];
        }
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
        result = parent[b][i];
    }
    return result;
}

int new_LCA(int a, int b, int c)
{
    int anc1 = LCA(a, b);
    int anc2 = LCA(a, c);
    int anc3 = LCA(c, b);

    int result = anc3;
    if (level[result] < level[anc2])
        result = anc2;
    if (level[result] < level[anc1])
        result = anc1;
    return result;
}

void setTree(int cur, int pre)
{
    level[cur] = level[pre] + 1;
    parent[cur][0] = pre;

    for (int i = 1; i < MAX; i++)
    {
        if (!parent[parent[cur][i - 1]][i - 1])
            break;
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }

    for (auto it : adj[cur])
    {
        if (it == pre)
            continue;
        setTree(it, cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n-- > 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    setTree(1, 0);

    cin >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << new_LCA(a, b, c) << "\n";
    }
}