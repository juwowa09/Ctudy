#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<pair<vector<int>, int>> v;
int n = 0, l = 0x7FFFFFFF, r = 0;

bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
    if (a.first[1] == b.first[1])
        return a.first[0] < b.first[0];
    return a.first[1] > b.first[1];
}

void inorder(int index, int l, int r)
{
    if (index >= n)
        return;

    result[0].push_back(v[index].second);

    for (int i = index + 1; i < n; i++)
    {
        if (v[i].first[0] > v[index].first[0] || v[i].first[0] < l || v[i].first[0] > r)
            continue;
        inorder(i, l, v[index].first[0]);
        break;
    }
    for (int i = index + 1; i < n; i++)
    {
        if (v[i].first[0] < v[index].first[0] || v[i].first[0] < l || v[i].first[0] > r)
            continue;
        inorder(i, v[index].first[0], r);
        break;
    }

    result[1].push_back(v[index].second);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    for (auto i : nodeinfo)
    {
        n++;
        vector<int> arr;
        for (auto j : i)
        {
            arr.push_back(j);
        }
        l = min(l, i[0]);
        r = max(r, i[0]);
        v.push_back({arr, n});
    }

    sort(v.begin(), v.end(), cmp);
    result.resize(2);

    inorder(0, l, r);

    vector<vector<int>> answer = result;
    return answer;
}