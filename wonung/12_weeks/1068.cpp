#include <iostream>
using namespace std;

int parent[50];
int leaf[50];

int find_P(int cur)
{
    if (parent[cur] == -1)
        return -1;
    else if (parent[cur] == -2)
        return -2;
    leaf[parent[cur]] = 1;
    return find_P(parent[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> parent[i];

    cin >> d;
    parent[d] = -2;
    for (int i = 0; i < n; i++)
    {
        if (find_P(i) == -2)
            leaf[i] = 1;
    }

    for (int i = 0; i < n; i++)
        if (leaf[i] == 0)
            cnt++;
    cout << cnt;
}