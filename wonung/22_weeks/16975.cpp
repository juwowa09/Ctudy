#include <iostream>
using namespace std;

int n, m;
int arr[100000];
long long seg[1 << 18];
long long lazy[1 << 18];
bool check[1 << 18];

void build(int cur, int st, int en)
{
    if (st == en)
    {
        seg[cur] = arr[st];
        return;
    }
    int mid = st + (en - st) / 2;

    build(2 * cur, st, mid);
    build(2 * cur + 1, mid + 1, en);
    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
}

void push_down(int cur, int st, int en, long long v)
{
    if (st == en)
    {
        seg[cur] += v;
        return;
    }
    lazy[cur] += v;
    seg[cur] += v * (en - st + 1);
    check[cur] = true;
}

void update(int cur, int st, int en, int l, int r, long long v)
{
    if (st > r || en < l)
        return;
    if (st == en)
    {
        seg[cur] += v;
        return;
    }
    if (l <= st && en <= r)
    {
        lazy[cur] += v;
        check[cur] = true;
        seg[cur] += v * (en - st + 1);
        return;
    }
    int mid = st + (en - st) / 2;

    if (check[cur])
    {
        check[cur] = false;
        push_down(2 * cur, st, mid, lazy[cur]);
        push_down(cur * 2 + 1, mid + 1, en, lazy[cur]);
        lazy[cur] = 0;
    }
    update(cur * 2, st, mid, l, r, v);
    update(cur * 2 + 1, mid + 1, en, l, r, v);

    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
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
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q, a, b, c;
        cin >> q;
        if (q == 1)
        {
            cin >> a >> b >> c;
            update(1, 0, n - 1, a - 1, b - 1, c);
        }
        else
        {
            cin >> a;
            cout << query(1, 0, n - 1, a - 1, a - 1) << "\n";
        }
    }
}