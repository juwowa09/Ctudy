#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<pair<int, int>> seg;

void child(int cur)
{
    if (seg[cur * 2].first < seg[cur * 2 + 1].first)
    {
        seg[cur].first = seg[cur * 2].first;
        seg[cur].second = seg[cur * 2].second;
    }
    else if (seg[cur * 2].first > seg[cur * 2 + 1].first)
    {
        seg[cur].first = seg[cur * 2 + 1].first;
        seg[cur].second = seg[cur * 2 + 1].second;
    }
    else
    {
        seg[cur].first = seg[cur * 2 + 1].first;
        seg[cur].second = min(seg[cur * 2].second, seg[cur * 2 + 1].second);
    }
}

void build(int cur, int st, int en)
{
    if (st == en)
    {
        seg[cur].first = arr[st];
        seg[cur].second = st;
        return;
    }

    int mid = st + (en - st) / 2;
    build(cur * 2, st, mid);
    build(cur * 2 + 1, mid + 1, en);

    child(cur);
}

void update(int cur, int st, int en, int pos, int v)
{
    if (en < pos || st > pos)
        return;
    if (st == en)
    {
        seg[cur].first = v;
        return;
    }

    int mid = st + (en - st) / 2;
    update(cur * 2, st, mid, pos, v);
    update(cur * 2 + 1, mid + 1, en, pos, v);

    child(cur);
}

pair<int, int> ss(int cur, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return {0x7FFFFFFF, 0};
    if (l <= st && en <= r)
        return seg[cur];

    int mid = st + (en - st) / 2;
    auto ll = ss(cur * 2, st, mid, l, r);
    auto rr = ss(cur * 2 + 1, mid + 1, en, l, r);

    if (ll.first > rr.first)
        return rr;
    else
        return ll;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 0, n - 1, b - 1, c);
        else
            cout << ss(1, 0, n - 1, b - 1, c - 1).second + 1 << "\n";
    }
}