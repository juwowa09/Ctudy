#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[1001];
int visit[1001];
int n;

void dfs(int st)
{
    visit[st] = 1;
    cout << st << " ";
    for (int i : v[st])
    {
        if (visit[i] == 1)
            continue;
        dfs(i);
    }
}

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    visit[st] = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";
        for (int i : v[f])
        {
            if (visit[i] == 1)
                continue;
            visit[i] = 1;
            q.push(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, st, k, en;
    cin >> n >> m >> st;

    for (int i = 0; i < m; i++)
    {
        cin >> k >> en;
        v[k].push_back(en);
        v[en].push_back(k);
    }
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());

    dfs(st);
    cout << "\n";
    fill(visit, visit + n + 1, 0);
    bfs(st);
}