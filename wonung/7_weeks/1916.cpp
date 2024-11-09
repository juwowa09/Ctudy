#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bool cmp(pair<int,int> a,pair<int,int> b){
//     if (a.first == b.first)
//         return a.second < b.second;
//     return a.first < b.first;
// }

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int dijkstra(vector<pair<int, int>> *v, int n, int st, int en)
{
    int *d = new int[n + 1];
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   cmp>
        heap;
    fill(d, d + n + 1, 100000000);
    d[st] = 0;
    heap.push({st, d[st]});
    while (!heap.empty())
    {
        pair<int, int> cur = heap.top();
        heap.pop();
        if (cur.first == en)
        {
            int value = d[cur.first];
            delete[] d;
            return value;
        }
        if (d[cur.first] != cur.second)
            continue;
        for (auto it = v[cur.first].begin(); it != v[cur.first].end(); it++)
        {
            if (d[it->first] <= cur.second + it->second)
                continue;
            d[it->first] = cur.second + it->second;
            heap.push({it->first, d[it->first]});
        }
    }
    delete[] d;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, st, en, w;
    cin >> n >> m;
    vector<pair<int, int>> *v = new vector<pair<int, int>>[n + 1];
    for (int i = 1; i <= m; i++)
    {
        cin >> st >> en >> w;
        v[st].push_back({en, w});
    }
    cin >> st >> en;
    cout << dijkstra(v, n, st, en);
    delete[] v;
}