#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int n, sy, sx, cnt = 0, st, en, result = 0x7FFFFFFF;
char map[50][50];
int map2[50][50];
bool visited[50][50];
set<int> s;
vector<int> v;

pair<int, int> pos[8]{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

bool bfs(int l, int h)
{
    queue<pair<int, int>> q;
    int count = 0;
    int l_m = 0x7FFFFFFF, h_m = 0;

    if (map2[sy][sx] >= l && map2[sy][sx] <= h)
        q.push({sy, sx});
    else
        return false;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    visited[sy][sx] = true;

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        h_m = max(h_m, map2[f.first][f.second]);
        l_m = min(l_m, map2[f.first][f.second]);
        for (int i = 0; i < 8; i++)
        {
            int n_r = f.first + pos[i].first;
            int n_c = f.second + pos[i].second;

            if (n_r >= n || n_r < 0 || n_c >= n || n_c < 0 || map2[n_r][n_c] < l || map2[n_r][n_c] > h || visited[n_r][n_c])
                continue;

            visited[n_r][n_c] = true;
            q.push({n_r, n_c});
            if (map[n_r][n_c] == 'K')
                count++;
        }
    }

    if (count == cnt)
    {
        result = min(result, h_m - l_m);
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
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'P')
            {
                sy = i;
                sx = j;
            }
            else if (map[i][j] == 'K')
                cnt++;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map2[i][j];
            s.insert(map2[i][j]);
        }

    for (auto it : s)
        v.push_back(it);

    while (en < v.size())
    {
        if (bfs(v[st], v[en]))
        {
            st++;
        }
        else
        {
            en++;
        }
    }
    cout << result;
}