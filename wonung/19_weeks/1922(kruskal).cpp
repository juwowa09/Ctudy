#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100000001
using namespace std;

int n, m, result = 0;
int group[1001];
vector<pair<int, pair<int, int>>> e;

int find_g(int x)
{
    if (0 < group[x])
        return group[x] = find_g(group[x]);
    return x;
}

void merge(int a, int b, int l)
{
    if (group[a] < group[b])
    {
        group[a] += group[b] - l;
        group[b] = a;
    }
    else
    {
        group[b] += group[a] - l;
        group[a] = b;
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
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({c, {a, b}});
    }
    sort(e.begin(), e.end());

    fill(group, group + 1 + n, 0);

    for (auto it : e)
    {
        int gx = find_g(it.second.first);
        int gy = find_g(it.second.second);
        if (gx != gy)
        {
            merge(gx, gy, it.first);
            result = min(group[gy], min(result, group[gx]));
        }
    }
    cout << result * -1;
}