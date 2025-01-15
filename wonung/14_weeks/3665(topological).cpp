#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> score;
vector<int> indegree;
int n;

void topological()
{
    queue<int> q;
    queue<int> win;
    int result = 0;
    bool flag = false;

    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int f = q.front();
        result++;
        q.pop();
        win.push(f);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (adj[f][i] == 1)
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                    cnt++;
                }
            }
        }
        if (cnt > 1)
            flag = true;
    }
    if (result == n && flag == false)
    {
        while (!win.empty())
        {
            cout << win.front() << " ";
            win.pop();
        }
        cout << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        adj.resize(n + 1, vector<int>(n + 1, 0));
        score.resize(n + 1, 0);
        indegree.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> score[i];
            for (int j = 1; j < i; j++)
            {
                adj[score[j]][score[i]] = 1;
                indegree[score[i]]++;
            }
        }
        cin >> m;
        while (m--)
        {
            cin >> a >> b;
            if (adj[a][b] == 1)
            {
                adj[a][b] = 0;
                adj[b][a] = 1;
                indegree[b]--;
                indegree[a]++;
            }
            else if (adj[b][a] == 1)
            {
                adj[a][b] = 1;
                adj[b][a] = 0;
                indegree[b]++;
                indegree[a]--;
            }
        }
        topological();
        adj.clear();
        score.clear();
        indegree.clear();
    }
}