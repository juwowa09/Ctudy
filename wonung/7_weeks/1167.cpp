#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<pair<int, int>> *v, int st, int *d, int n)
{
    fill(d, d + n + 1, (int)1e9);
    d[st] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    heap.push({d[st], st});
    while (!heap.empty())
    {
        auto cur = heap.top();
        heap.pop();
        if (cur.first != d[cur.second])
            continue;
        for (auto it : v[cur.second])
        {
            if (d[it.first] < cur.first + it.second)
                continue;
            d[it.first] = cur.first + it.second;
            heap.push({d[it.first], it.first});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, st, en, w, max = 0, idx;

    cin >> n;
    int *arr = new int[n + 1];
    vector<pair<int, int>> *v = new vector<pair<int, int>>[n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> st;
        cin >> en;
        while (en != -1)
        {
            cin >> w;
            v[st].push_back({en, w});
            cin >> en;
        }
    }
    dijkstra(v, 1, arr, n);
    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            idx = i;
        }
    }
    max = 0;
    dijkstra(v, idx, arr, n);
    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << max;
}