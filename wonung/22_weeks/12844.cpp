#include <iostream>
using namespace std;

int n, m;
int arr[500000];
int seg[1 << 20];
int lazy[1 << 20];

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

    seg[cur] = seg[cur * 2] ^ seg[cur * 2 + 1];
}

void push_down(int cur, int st, int en, int v)
{
    if (st == en)
    {
        seg[cur] ^= v;
        return;
    }
    lazy[cur] ^= v;
    if ((en - st + 1) % 2)
        seg[cur] ^= v;
}

void update(int cur, int st, int en, int l, int r, int v)
{
    if (st > r || en < l)
        return;
    if (l <= st && en <= r)
    {
        lazy[cur] ^= v;
        if ((en - st + 1) % 2)
            seg[cur] ^= v;
        return;
    }
    int mid = st + (en - st) / 2;

    if (lazy[cur])
    {
        push_down(cur * 2, st, mid, lazy[cur]);
        push_down(cur * 2 + 1, mid + 1, en, lazy[cur]);
        lazy[cur] = 0;
    }

    update(cur * 2, st, mid, l, r, v);
    update(cur * 2 + 1, mid + 1, en, l, r, v);

    seg[cur] = seg[cur * 2] ^ seg[cur * 2 + 1];
}

int query(int cur, int st, int en, int l, int r)
{
    if (l > en || st > r)
        return 0;
    if (l <= st && en <= r)
        return seg[cur];

    int mid = st + (en - st) / 2;

    if (lazy[cur])
    {
        push_down(cur * 2, st, mid, lazy[cur]);
        push_down(cur * 2 + 1, mid + 1, en, lazy[cur]);
        lazy[cur] = 0;
    }
    int l_q = query(cur * 2, st, mid, l, r);
    int r_q = query(cur * 2 + 1, mid + 1, en, l, r);
    return l_q ^ r_q;
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
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            update(1, 0, n - 1, b, c, d);
        }
        else
        {
            cin >> b >> c;
            cout << query(1, 0, n - 1, b, c) << "\n";
        }
    }
}