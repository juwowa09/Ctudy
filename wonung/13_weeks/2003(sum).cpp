#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = 0, sum = 0, st = 0, en = 0;
    cin >> n >> m;
    vector<long> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    while (en <= n)
    {
        int sum = v[en] - v[st];
        if (sum < m)
            en++;
        else
        {
            if (sum == m)
                result++;
            st++;
        }
    }
    cout << result;
}