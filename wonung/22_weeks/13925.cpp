#include <iostream>
#define M 1000000007
using namespace std;

int n, m;
long long arr[100000];
long long seg[1 << 18];
long long lazy_p[1 << 18];
long long lazy_m[1 << 18];

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

    seg[cur] = (seg[cur * 2] + seg[cur * 2 + 1]) % M;
}

void push_down(int cur, int st, int en, long long v, int t)
{
    if (st == en)
    {
        if (t == 1)
            seg[cur] = (seg[cur] + v) % M;
        if (t == 2)
            seg[cur] = (seg[cur] * v) % M;
        return;
    }
    if (t == 1)
    {
        lazy_p[cur] = (lazy_p[cur] + v) % M;
        seg[cur] = (seg[cur] + (v * (en - st + 1)) % M) % M;
    }
    else if (t == 2)
    {
        lazy_p[cur] = (lazy_p[cur] * v) % M;
        lazy_m[cur] = (lazy_m[cur] * v) % M;
        seg[cur] = (seg[cur] * v) % M;
    }
}

void update(int cur, int st, int en, int l, int r, long long v, int t)
{
    if (st > r || en < l)
        return;
    if (st == en)
    {
        if (t == 1)
            seg[cur] = (seg[cur] + v) % M;
        else if (t == 2)
            seg[cur] = (seg[cur] * v) % M;
        else
            seg[cur] = v;
        return;
    }
    if (l <= st && en <= r)
    {
        if (t == 1)
        {
            seg[cur] = (seg[cur] + (v * (en - st + 1)) % M) % M;
            lazy_p[cur] = (lazy_p[cur] + v) % M;
        }
        else if (t == 2)
        {
            seg[cur] = (seg[cur] * v) % M;
            lazy_p[cur] = (lazy_p[cur] * v) % M;
            lazy_m[cur] = (lazy_m[cur] * v) % M;
        }
        else
        {
            seg[cur] = (v * (en - st + 1)) % M;
            lazy_p[cur] = v;
            lazy_m[cur] = 0;
        }
        return;
    }
    int mid = st + (en - st) / 2;

    if (lazy_m[cur] != 1)
    {
        push_down(cur * 2, st, mid, lazy_m[cur], 2);
        push_down(cur * 2 + 1, mid + 1, en, lazy_m[cur], 2);
        lazy_m[cur] = 1;
    }
    if (lazy_p[cur])
    {
        push_down(cur * 2, st, mid, lazy_p[cur], 1);
        push_down(cur * 2 + 1, mid + 1, en, lazy_p[cur], 1);
        lazy_p[cur] = 0;
    }
    update(cur * 2, st, mid, l, r, v, t);
    update(cur * 2 + 1, mid + 1, en, l, r, v, t);

    seg[cur] = (seg[cur * 2] + seg[cur * 2 + 1]) % M;
}

long long query(int cur, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return 0;
    if (l <= st && en <= r)
        return seg[cur];
    int mid = st + (en - st) / 2;

    if (lazy_m[cur] != 1)
    {
        push_down(cur * 2, st, mid, lazy_m[cur], 2);
        push_down(cur * 2 + 1, mid + 1, en, lazy_m[cur], 2);
        lazy_m[cur] = 1;
    }
    if (lazy_p[cur])
    {
        push_down(cur * 2, st, mid, lazy_p[cur], 1);
        push_down(cur * 2 + 1, mid + 1, en, lazy_p[cur], 1);
        lazy_p[cur] = 0;
    }
    long long l_q = query(cur * 2, st, mid, l, r);
    long long r_q = query(cur * 2 + 1, mid + 1, en, l, r);

    return (l_q + r_q) % M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < (1 << 18); i++)
        lazy_m[i] = 1;

    for (int i = 0; i < m; i++)
    {
        int q, a, b, c;
        cin >> q;
        if (q == 1)
        {
            cin >> a >> b >> c;
            update(1, 0, n - 1, a - 1, b - 1, c, 1);
        }
        else if (q == 2)
        {
            cin >> a >> b >> c;
            update(1, 0, n - 1, a - 1, b - 1, c, 2);
        }
        else if (q == 3)
        {
            cin >> a >> b >> c;
            update(1, 0, n - 1, a - 1, b - 1, c, 3);
        }
        else
        {
            cin >> b >> c;
            cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
    }
}