#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result = 0;
pair<int, int> map[100][100];

pair<int, int> pos[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bfs()
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push({0, 0});
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            map[i][j].second = 0;

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = f.first + pos[i].first;
            int ncol = f.second + pos[i].second;
            if (nrow >= n || nrow < 0 || ncol >= m || ncol < 0)
                continue;
            if (map[nrow][ncol].first == 1) //   치즈의 경우
            {
                map[nrow][ncol].second++; //  공기와 닿은 면 카운팅
                if (map[nrow][ncol].second == 2)
                    v.push_back({nrow, ncol});
            }
            else
            { // 공기의 경우
                if (map[nrow][ncol].second == 1)
                    continue;               // 방문되어 있으면 넘김
                map[nrow][ncol].second = 1; // 공기 visit 처리
                q.push({nrow, ncol});
            }
        }
    }
    if (v.empty())
        return false;
    for (auto it = v.begin(); it != v.end(); it++)
        map[it->first][it->second].first = 0;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j].first;

    while (bfs())
        result++;
    cout << result;
}