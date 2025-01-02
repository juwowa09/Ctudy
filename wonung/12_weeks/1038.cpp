#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    bool flag = false;
    queue<long> q;
    vector<long> v;

    cin >> n;
    for (int i = 0; i < 10; i++)
        q.push(i);

    while (!q.empty())
    {
        long t = q.front();
        int last = t % 10;
        q.pop();
        v.push_back(t);
        if (v.size() == n + 1)
        {
            flag = true;
            break;
        }
        for (int i = 0; i < last; i++)
            q.push(t * 10 + i);
    }
    if (flag)
        cout << v[v.size() - 1];
    else
        cout << -1;
}