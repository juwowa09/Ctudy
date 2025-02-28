#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> seg;
vector<long long> lazy;
vector<bool> check;

void build(int cur, int st, int en)
{
    if (st == en)
    {
        seg[cur] = arr[st];
        return;
    }
    int mid = st + (en - st) / 2;
    build(cur * 2, st, mid);
    build(cur * 2 + 1, mid + 1, en);
    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
}

long long push_down(int cur, int st, int en, long long v)
{
    if (st == en)
        return seg[cur] += v;
    lazy[cur] += v;
    check[cur] = true;
    return seg[cur] += v * (en - st + 1);
}

long long update(int cur, int st, int en, int l, int r, long long v)
{
    if (l > en || st > r)
        return seg[cur];
    if (st == en)
        return seg[cur] += v;

    if (l <= st && en <= r)
    {
        check[cur] = true;
        lazy[cur] += v;
        return seg[cur] += v * (en - st + 1);
    }

    int mid = st + (en - st) / 2;

    if (check[cur])
    {
        check[cur] = false;
        push_down(cur * 2, st, mid, lazy[cur]);
        push_down(cur * 2 + 1, mid + 1, en, lazy[cur]);
        lazy[cur] = 0;
    }
    long long ll = update(cur * 2, st, mid, l, r, v);
    long long rr = update(cur * 2 + 1, mid + 1, en, l, r, v);

    return seg[cur] = ll + rr;
}

long long query(int cur, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return 0;
    if (l <= st && en <= r)
        return seg[cur];
    int mid = st + (en - st) / 2;

    if (check[cur])
    {
        check[cur] = false;
        push_down(cur * 2, st, mid, lazy[cur]);
        push_down(cur * 2 + 1, mid + 1, en, lazy[cur]);
        lazy[cur] = 0;
    }
    long long ll = query(cur * 2, st, mid, l, r);
    long long rr = query(cur * 2 + 1, mid + 1, en, l, r);

    return ll + rr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m >> k;
    arr.resize(n);
    seg.resize(n * 4);
    check.resize(n * 4, false);
    lazy.resize(n * 4, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);
    for (int i = 0; i < m + k; i++)
    {
        int a, b, c;
        long long d;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            update(1, 0, n - 1, b - 1, c - 1, d);
        }
        else
        {
            cin >> b >> c;
            cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
    }
}
