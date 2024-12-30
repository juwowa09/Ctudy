#include <iostream>
#include <queue>
using namespace std;

int visit[500][500];
int arr[500][500];

pair<int, int> d[4] = {
    {1, 0},
    {
        -1,
        0,
    },
    {0, 1},
    {0, -1}};

int dijkstra(int n, int m)
{
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        less<pair<int, pair<int, int>>>>
        heap;
    heap.push({arr[0][0], {0, 0}});
    visit[0][0] = 1;
    while (!heap.empty())
    {
        auto top = heap.top();
        heap.pop();
        int row = top.second.first;
        int col = top.second.second;
        if (row == n - 1 && col == m - 1)
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + d[i].first;
            int ncol = col + d[i].second;
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && arr[nrow][ncol] < arr[row][col])
            {
                if (visit[nrow][ncol] == 0)
                    heap.push({arr[nrow][ncol], {nrow, ncol}});
                visit[nrow][ncol] += visit[row][col];
            }
        }
    }
    return visit[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << dijkstra(n, m);
}