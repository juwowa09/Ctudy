#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
int dp[10001];
vector<int> mem;
vector<int> cost;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    mem.resize(n);
    cost.resize(101);
    for (int i = 0; i < n; i++)
        cin >> mem[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 10000; j >= cost[i]; j--)
            dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
    }

    for (int i = 0; i <= 10000; i++)
        if (dp[i] >= m)
        {
            cout << i;
            break;
        }
}