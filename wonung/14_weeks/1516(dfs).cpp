#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[501];
int v[501];
int dp[501];

int dfs(int it)
{
    if (adj[it].size() == 0)
        return v[it];
    if (dp[it] != 0)
        return dp[it];
    int sum = 0;
    for (int j : adj[it])
    {
        sum = max(sum, dfs(j));
    }
    // 다시 탐색하지 않도록
    dp[it] = sum + v[it];
    return sum + v[it];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        cin >> v[i];
        while (1)
        {
            cin >> k;
            if (k == -1)
                break;
            adj[i].push_back(k);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dfs(i);
        cout << dp[i] << "\n";
    }
}