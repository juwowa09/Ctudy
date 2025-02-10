#include <iostream>
#include <queue>
#define FOR(a, b, c) for (int a = b; a < c; a++)
using namespace std;

int n, m;
int visited[1000][1000];
int Map[1000][1000];

pair<int, int> pos[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    visited[r][c] = 0;
    q.push({r, c});

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = f.first + pos[i].first;
            int nc = f.second + pos[i].second;

            if (nr >= n || nr < 0 || nc >= m || nc < 0 || visited[nr][nc] != 0 || Map[nr][nc] == 0)
                continue;
            visited[nr][nc] = visited[f.first][f.second] + 1;
            q.push({nr, nc});
        }
    }
    visited[r][c] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int sr, sc;
    FOR(i, 0, n)
    FOR(j, 0, m)
    {
        cin >> Map[i][j];
        if (Map[i][j] == 2)
        {
            sr = i;
            sc = j;
        }
    }

    bfs(sr, sc);
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if (Map[i][j] == 1 && !visited[i][j])
                cout << -1 << " ";
            else
                cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}