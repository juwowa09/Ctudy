#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> score;
vector<int> indegree;
int n;

void sol()
{
    queue<int> win;
    vector<pair<int, int>> v;
    int pre = -1;
    bool flag = false;

    for (int i = 1; i <= n; i++)
        v.push_back({indegree[i], i});
    sort(v.begin(), v.end(), less<pair<int, int>>());

    for (int i = 0; i < n; i++)
    {
        if (pre == v[i].first)
        {
            flag = true;
            break;
        }
        pre = v[i].first;
        win.push(v[i].second);
    }

    if (flag == false)
    {
        while (!win.empty())
        {
            cout << win.front() << " ";
            win.pop();
        }
        cout << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, m, a, b, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        score.resize(n + 1, 0);
        indegree.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            score[k] = i;
            indegree[k] = i - 1;
        }
        cin >> m;
        while (m--)
        {
            cin >> a >> b;
            if (score[a] > score[b])
            {
                indegree[b]++;
                indegree[a]--;
            }
            else
            {
                indegree[b]--;
                indegree[a]++;
            }
        }
        sol();
    }
}