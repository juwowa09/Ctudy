#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int find_group(int group[], int x)
{
    if (x != group[x])
        return group[x] = find_group(group, group[x]); // 경로 압축
    return x;
}
void merge(int x, int y, int group[])
{
    int gx = find_group(group, x);
    int gy = find_group(group, y);

    if (gx != gy)
    {
        if (gx < gy)
            group[gy] = group[gx];
        else
            group[gx] = group[gy];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, know, know_Person, cnt;
    vector<pair<int, int *>> v;
    int group[53];

    cin >> n >> m;
    cin >> know;

    cnt = m;
    v.resize(m);
    // 초기화
    for (int i = 0; i <= n; i++)
    {
        group[i] = i;
    }

    for (int i = 0; i < know; i++)
    {
        cin >> know_Person;
        group[know_Person] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first;
        v[i].second = new int[v[i].first];
        for (int j = 0; j < v[i].first; j++)
        {
            cin >> v[i].second[j];
        }
        int temp = v[i].second[0];
        for (int j = 1; j < v[i].first; j++)
        {
            merge(temp, v[i].second[j], group);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < v[i].first; j++)
            if (find_group(group, v[i].second[j]) == 0)
            {
                cnt--;
                break;
            }
        delete[] v[i].second;
    }
    cout << cnt;
}