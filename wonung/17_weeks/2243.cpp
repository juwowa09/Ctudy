#include <iostream>
#include <map>
using namespace std;

int n;
int tree[4000001];

int update(int cur, int l, int r, int pos, int value)
{
    if (l > pos || r < pos)
        return tree[cur];
    if (l == r)
        return tree[cur] += value;

    int mid = l + (r - l) / 2;
    return tree[cur] = update(2 * cur, l, mid, pos, value) +
                       update(2 * cur + 1, mid + 1, r, pos, value);
}

int search(int cur, int value, int l, int r)
{
    if (l == r)
        return l;
    int mid = l + (r - l) / 2;

    if (tree[cur * 2] >= value)
        return search(cur * 2, value, l, mid);
    else
        return search(cur * 2 + 1, value - tree[cur * 2], mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            int pos = search(1, b, 1, 1000000);
            cout << pos << "\n";
            update(1, 1, 1000000, pos, -1);
        }
        else
        {
            cin >> b >> c;
            update(1, 1, 1000000, b, c);
        }
    }
}