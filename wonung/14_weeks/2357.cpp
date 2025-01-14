#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree;
vector<int> arr;

void build(int cur, int st, int en)
{
    if (st == en)
    {
        tree[cur].first = arr[st];
        tree[cur].second = arr[st];
        return;
    }
    int mid = st + (en - st) / 2;

    build(2 * cur, st, mid);
    build(2 * cur + 1, mid + 1, en);
    tree[cur].first = max(tree[cur * 2].first, tree[cur * 2 + 1].first);
    tree[cur].second = min(tree[cur * 2].second, tree[cur * 2 + 1].second);
}

pair<int, int> Range(int cur, int r_st, int r_en, int st, int en)
{
    if (st <= r_st && r_en <= en)
        return tree[cur];
    if (st > r_en || en < r_st)
        return {0, 1000000001};

    int mid = r_st + (r_en - r_st) / 2;
    auto l = Range(cur * 2, r_st, mid, st, en);
    auto r = Range(cur * 2 + 1, mid + 1, r_en, st, en);
    return {max(l.first, r.first), min(l.second, r.second)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;

    arr.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        auto result = Range(1, 0, n - 1, a - 1, b - 1);
        cout << result.second << " " << result.first << "\n";
    }
}