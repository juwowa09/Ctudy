#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dp[501];
int arr[501];
vector<int> adj[501];

void dfs(int num)
{
    for (auto it : adj[num])
    {
        if (dp[it] == 0)
            dfs(it);
        dp[num] = max(dp[num], dp[it]);
    }
    dp[num] += arr[num];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> arr[i];
        while (1)
        {
            cin >> a;
            if (a == -1)
                break;
            adj[i].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
            dfs(i);
        cout << dp[i] << "\n";
    }
}