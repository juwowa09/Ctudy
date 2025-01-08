#include <iostream>
#include <queue>
using namespace std;

pair<int, int> pos[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int map[20][20];
int visit[20][20];
int row, col, n, Ssize = 2, cnt = 0, result = 0;

bool bfs()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visit[i][j] = 0;
    queue<pair<int, pair<int, int>>> q;
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    q.push({0, {row, col}});
    visit[row][col] = 1;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        int n_row = f.second.first;
        int n_col = f.second.second;
        if (map[n_row][n_col] > 0 && Ssize > map[n_row][n_col])
            pq.push({f.first, {n_row, n_col}});
        for (int i = 0; i < 4; i++)
        {
            int nrow = f.second.first + pos[i].first;
            int ncol = f.second.second + pos[i].second;
            if (nrow >= n || nrow < 0 || ncol >= n || ncol < 0 || map[nrow][ncol] > Ssize || visit[nrow][ncol] == 1)
                continue;
            if (Ssize >= map[nrow][ncol])
            {
                q.push({f.first + 1, {nrow, ncol}});
                visit[nrow][ncol] = 1;
            }
        }
    }
    if (!pq.empty())
    {
        row = pq.top().second.first;
        col = pq.top().second.second;
        map[row][col] = 0;
        cnt++;
        if (cnt == Ssize)
        {
            cnt = 0;
            Ssize++;
        }
        result += pq.top().first;
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                map[i][j] = 0;
                row = i;
                col = j;
            }
        }
    }

    while (bfs())
    {
    }
    cout << result;
}
