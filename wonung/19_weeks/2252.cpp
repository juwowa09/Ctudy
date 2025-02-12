#include <iostream>
#include <queue>
using namespace std;

int n, m;
int indgree[32001];
vector<int> adj[32001];

void topological()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (indgree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        auto f = q.front();
        cout << f << " ";
        q.pop();

        for (auto it : adj[f])
        {
            indgree[it]--;

            if (indgree[it] == 0)
                q.push(it);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        indgree[b]++;
        adj[a].push_back(b);
    }
    topological();
}