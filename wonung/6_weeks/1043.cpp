#include <iostream>
#include <vector>

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

    // 항상 작은 쪽으로 merge 하도록 한다.
    // group 0 을 진실을 알고있는 사람으로 잡았기 때문.
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

    cin >> n >> m;
    cin >> know;

    cnt = m;
    v.resize(m);
    int *group = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        group[i] = i;
    }

    // 진실을 알고있는 group = 0
    for (int i = 0; i < know; i++)
    {
        cin >> know_Person;
        group[know_Person] = 0;
    }

    // m 개의 모임 사람 입력받고, 한 모임의 모든 사람을 union-find 수행.
    for (int i = 0; i < m; i++)
    {
        // 한 모임 최대 사람 수
        cin >> v[i].first;
        v[i].second = new int[v[i].first];

        // 사람 입력
        for (int j = 0; j < v[i].first; j++)
        {
            cin >> v[i].second[j];
            merge(v[i].second[0], v[i].second[j], group);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (find_group(group, v[i].second[0]) == 0)
            cnt--;
        delete[] v[i].second;
    }
    cout << cnt;
}