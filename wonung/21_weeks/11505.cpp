#include <iostream>
#include <queue>
#define MAX 1000000007
using namespace std;

int n, m, k;

vector<long long> seg;
vector<int> arr;

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
    seg[cur] = (seg[cur * 2] * seg[cur * 2 + 1]) % MAX;
}

long long sear(int cur, int st, int en, int l, int r)
{
    if (en < l || st > r)
        return 1;
    if (l <= st && en <= r)
        return seg[cur];

    int mid = st + (en - st) / 2;

    return (sear(cur * 2, st, mid, l, r) * sear(cur * 2 + 1, mid + 1, en, l, r)) % MAX;
}

long long update(int cur, int st, int en, int pos, int value)
{
    if (pos < st || pos > en)
        return seg[cur];
    if (st == en)
        return seg[cur] = value;

    int mid = st + (en - st) / 2;

    long long l = update(cur * 2, st, mid, pos, value);
    long long r = update(cur * 2 + 1, mid + 1, en, pos, value);

    seg[cur] = (l * r) % MAX;
    return seg[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    arr.resize(n);
    seg.resize(4 * n, 1);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    for (int i = 0; i < m + k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a)
        {
        case 1:
            update(1, 0, n - 1, b - 1, c);
            break;
        case 2:
            cout << sear(1, 0, n - 1, b - 1, c - 1) << "\n";
            break;
        }
    }
}