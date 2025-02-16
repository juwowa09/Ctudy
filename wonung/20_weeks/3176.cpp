#include <iostream>
#include <vector>
#define MAX 18
using namespace std;

int n;

int parent[100001][MAX + 1];
int level[100001];
pair<int, int> length[100001][MAX + 1];
vector<pair<int, int>> adj[100001];

pair<int, int> LCA(int a, int b)
{
    if (level[a] < level[b])
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    pair<int, int> result = length[a][0];

    if (level[a] != level[b])
    {
        for (int i = MAX; i >= 0; i--)
        {
            if (level[parent[a][i]] >= level[b])
            {
                result.first = min(length[a][i].first, result.first);
                result.second = max(length[a][i].second, result.second);
                a = parent[a][i];
            }
        }
    }

    if (a == b)
        return result;

    for (int i = MAX; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            result.first = min(length[b][i].first, min(length[a][i].first, result.first));
            result.second = max(length[b][i].second, max(length[a][i].second, result.second));

            a = parent[a][i];
            b = parent[b][i];
        }
        result.first = min(length[b][0].first, min(length[a][0].first, result.first));
        result.second = max(length[b][0].second, max(length[a][0].second, result.second));
    }
    return result;
}

void setTree(int c, int p, int value)
{
    parent[c][0] = p;
    length[c][0].first = value;
    length[c][0].second = value;
    level[c] = level[p] + 1;

    for (int i = 1; i <= MAX; i++)
    {
        parent[c][i] = parent[parent[c][i - 1]][i - 1];
        length[c][i].first = min(length[parent[c][i - 1]][i - 1].first, length[c][i - 1].first);
        length[c][i].second = max(length[parent[c][i - 1]][i - 1].second, length[c][i - 1].second);
    }

    for (auto it : adj[c])
    {
        if (it.first == p)
            continue;
        setTree(it.first, c, it.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b, c, k;
    for (int i = 0; i < n - 1; i++)
    {

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= MAX; j++)
            length[i][j].first = 0x7FFFFFFF;

    setTree(1, 0, 0);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        auto mid = LCA(a, b);
        cout << mid.first << " " << mid.second << "\n";
    }
}