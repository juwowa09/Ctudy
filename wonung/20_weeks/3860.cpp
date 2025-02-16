#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int w, h, g, e, x1, x2, yy, y2, t;

long long dist[30][30];
int Map[30][30];
unordered_map<int, pair<int, int>> m;

pair<int, int> pos[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bell()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            dist[i][j] = 0x7FFFFFFF;

    dist[0][0] = 0;
    for (int k = 0; k < w * h; k++)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (dist[i][j] == 0x7FFFFFFF || (i == h - 1 && j == w - 1))
                    continue;

                if (Map[i][j] == 1)
                {
                    for (int r = 0; r < 4; r++)
                    {
                        int ny = i + pos[r].first;
                        int nx = j + pos[r].second;
                        if (nx >= w || nx < 0 || ny >= h || ny < 0 || Map[ny][nx] == 0)
                            continue;
                        if (dist[ny][nx] > dist[i][j] + 1)
                        {
                            if (k == w * h - 1)
                                return false;
                            dist[ny][nx] = dist[i][j] + 1;
                        }
                    }
                }
                else
                {
                    if (dist[m[i * w + j].second / w][m[i * w + j].second % w] > dist[i][j] + m[i * w + j].first)
                    {
                        if (w * h - 1 == k)
                            return false;
                        dist[m[i * w + j].second / w][m[i * w + j].second % w] = dist[i][j] + m[i * w + j].first;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        m.clear();

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                Map[i][j] = 1;

        cin >> g;
        for (int i = 0; i < g; i++)
        {
            cin >> x1 >> yy;
            Map[yy][x1] = 0;
        }

        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cin >> x1 >> yy >> x2 >> y2 >> t;
            Map[yy][x1] = 2;
            m[yy * w + x1] = {t, y2 * w + x2};
        }
        if (!bell())
            cout << "Never\n";
        else
        {
            if (dist[h - 1][w - 1] == 0x7FFFFFFF)
                cout << "Impossible\n";
            else
                cout << dist[h - 1][w - 1] << "\n";
        }
    }
}