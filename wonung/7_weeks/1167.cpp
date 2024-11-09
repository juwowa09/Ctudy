#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<pair<int, int>> *v, pair<int, int> *p, int *visit, int prev)
{
    if (visit[p->first] != -1)
        return;
    visit[p->first] = prev + p->second;
    for (auto it : v[p->first])
        dfs(v, &it, visit, visit[p->first]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, st, en, w, max = 0, idx;

    cin >> n;
    int *visit = new int[n + 1];
    vector<pair<int, int>> *v = new vector<pair<int, int>>[n + 1];

    for (int i = 0; i < n; i++)
    {
        visit[i] = -1;
        cin >> st;
        cin >> en;
        while (en != -1)
        {
            cin >> w;
            v[st].push_back({en, w});
            cin >> en;
        }
    }
    visit[n] = -1;
    pair<int, int> p = {1, 0};
    dfs(v, &p, visit, 0);
    for (int i = 0; i < n + 1; i++)
    {
        if (max < visit[i])
        {
            max = visit[i];
            idx = i;
        }
        visit[i] = -1;
    }
    max = 0;
    p = {idx, 0};
    dfs(v, &p, visit, 0);
    for (int i = 0; i < n + 1; i++)
    {
        if (max < visit[i])
            max = visit[i];
    }
    cout << max;
    delete[] visit;
    delete[] v;
}