#include <iostream>
#include <unordered_set>
using namespace std;

int n, m, cnt;
int map[8][8];

pair<int, int> pos[4] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int direct(int row, int col, int dir, int count, unordered_set<int> *s)
{
    int r = row;
    int c = col;
    while (r + pos[dir].first < n && r + pos[dir].first >= 0 && c + pos[dir].second < m && c + pos[dir].second >= 0)
    {
        r = r + pos[dir].first;
        c = c + pos[dir].second;
        if (map[r][c] == 6)
            break;
        else if (map[r][c] == 0)
        {
            s->insert(r * m + c);
            map[r][c] = '#';
            count--;
        }
    }
    return count;
}

void dfs(int row, int col, int count)
{
    if (col >= m)
    {
        row++;
        col = 0;
    }
    if (row >= n)
    {
        cnt = min(cnt, count);
        return;
    }
    if (count > cnt)
        return;

    unordered_set<int> s;
    if (map[row][col] == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            s.clear();
            int tmp = direct(row, col, i, count, &s);

            dfs(row, col + 1, tmp);
            for (auto it = s.begin(); it != s.end(); it++)
                map[*it / m][*it % m] = 0;
        }
    }
    else if (map[row][col] == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            s.clear();
            int tmp = direct(row, col, i, count, &s);
            tmp = direct(row, col, i + 2, tmp, &s);

            dfs(row, col + 1, tmp);

            for (auto it = s.begin(); it != s.end(); it++)
                map[*it / m][*it % m] = 0;
        }
    }
    else if (map[row][col] == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            s.clear();
            int tmp = direct(row, col, i, count, &s);
            tmp = direct(row, col, (i + 1) % 4, tmp, &s);

            dfs(row, col + 1, tmp);

            for (auto it = s.begin(); it != s.end(); it++)
                map[*it / m][*it % m] = 0;
        }
    }
    else if (map[row][col] == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            s.clear();
            int tmp = direct(row, col, i, count, &s);
            tmp = direct(row, col, (i + 1) % 4, tmp, &s);
            tmp = direct(row, col, (i + 2) % 4, tmp, &s);

            dfs(row, col + 1, tmp);

            for (auto it = s.begin(); it != s.end(); it++)
                map[*it / m][*it % m] = 0;
        }
    }
    else if (map[row][col] == 5)
    {
        s.clear();
        int tmp = direct(row, col, 0, count, &s);
        tmp = direct(row, col, 1, tmp, &s);
        tmp = direct(row, col, 2, tmp, &s);
        tmp = direct(row, col, 3, tmp, &s);

        dfs(row, col + 1, tmp);

        for (auto it = s.begin(); it != s.end(); it++)
            map[*it / m][*it % m] = 0;
    }
    else
    {
        dfs(row, col + 1, count);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                cnt++;
        }

    dfs(0, 0, cnt);
    cout << cnt;
}