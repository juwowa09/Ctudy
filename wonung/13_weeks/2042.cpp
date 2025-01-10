#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;

struct segtree
{
    int size;
    vector<long long> tree;

    void build(int n)
    {
        size = n;
        tree.resize(4 * n);
    }

    long long buildRec(int cur, int left, int right)
    {
        if (left == right)
        {
            return tree[cur] = arr[left];
        }
        int mid = left + (right - left) / 2;
        long long val_left = buildRec(2 * cur, left, mid);
        long long val_right = buildRec(2 * cur + 1, mid + 1, right);

        return tree[cur] = val_left + val_right; // 필요에 따라 연산 변경 가능.
    }

    long long searchRec(int left, int right, int cur, int l_range, int r_range)
    {
        if (left > r_range || right < l_range)
            return 0;

        if (left <= l_range && r_range <= right)
            return tree[cur];

        int mid = l_range + (r_range - l_range) / 2;
        return searchRec(left, right, cur * 2, l_range, mid) + searchRec(left, right, cur * 2 + 1, mid + 1, r_range);
    }

    long long update(int p, long long c, int left, int right, int cur)
    {
        if (right < p || left > p)
            return tree[cur];

        if (left == right)
            return tree[cur] = c;

        int mid = left + (right - left) / 2;
        long long l = update(p, c, left, mid, cur * 2);
        long long r = update(p, c, mid + 1, right, cur * 2 + 1);
        return tree[cur] = l + r;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, a, b;
    long long c;
    cin >> n >> m >> k;
    arr.resize(n);
    segtree seg;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    seg.build(n);
    seg.buildRec(1, 0, n - 1);

    for (int i = 0; i < m + k; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
            seg.update(b - 1, c, 0, n - 1, 1);
        if (a == 2)
            cout << seg.searchRec(b - 1, c - 1, 1, 0, n - 1) << "\n";
    }
}