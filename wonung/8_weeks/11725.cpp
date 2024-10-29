#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> *v, int *visit, int *arr)
{
    queue<pair<int, int>> q;
    for (auto iter = v[1].begin(); iter != v[1].end(); iter++)
    {
        q.push({1, *iter});
    }
    visit[1] = 1;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        if (visit[top.second])
            continue;
        visit[top.second] = 1;
        for (auto iter = v[top.second].begin(); iter != v[top.second].end(); iter++)
        {
            q.push({top.second, *iter});
        }
        arr[top.second] = top.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n;

    int *visit = new int[n + 1];
    int *arr = new int[n + 1];
    vector<int> *v = new vector<int>[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        visit[i] = 0;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    visit[n] = 0;
    visit[n - 1] = 0;
    bfs(v, visit, arr);
    for (int i = 2; i <= n; i++)
        cout << arr[i] << "\n";
    delete[] v;
    delete[] arr;
    delete[] visit;
}