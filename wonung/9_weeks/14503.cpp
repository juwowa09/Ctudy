#include <iostream>
#include <queue>
using namespace std;

pair<int, int> dis[4] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

int arr[50][50];
int result = 0;

void clean(int r, int c, int d, int n, int m)
{
    if (arr[r][c] == 0)
    {
        arr[r][c] = 2;
        result++;
    }
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dis[(d + 3 - i) % 4].first;
        int cc = c + dis[(d + 3 - i) % 4].second;
        int v = (d + 3 - i) % 4;
        if (rr >= 0 && cc >= 0 && rr < n && cc < m && arr[rr][cc] == 0)
        {
            return clean(rr, cc, v, n, m);
        }
    }
    // back
    int br = r + dis[(d + 2) % 4].first;
    int bc = c + dis[(d + 2) % 4].second;
    if (br < 0 || bc < 0 || br >= n || bc >= m || arr[br][bc] == 1)
        return;
    return clean(br, bc, d, n, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    clean(r, c, d, n, m);
    cout << result;
}