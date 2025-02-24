#include <iostream>
#include <vector>
#define MAX 18
using namespace std;

int n, r, m;
int tree_num[100001];
vector<int> adj[100001];
vector<int> child[100001];

int subTreeSize(int cur)
{
    if (tree_num[cur] != -1)
        return tree_num[cur];
    if (adj[cur].empty())
        return tree_num[cur] = 1;

    tree_num[cur] = 1;
    for (auto it : child[cur])
        tree_num[cur] += subTreeSize(it);

    return tree_num[cur];
}

void setTree(int cur, int pre)
{
    for (auto it : adj[cur])
    {
        if (it == pre)
            continue;
        child[cur].push_back(it);
        setTree(it, cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    setTree(r, 0);
    fill(tree_num, tree_num + n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        cout << subTreeSize(a) << "\n";
    }
}