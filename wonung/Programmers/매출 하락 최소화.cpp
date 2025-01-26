#include <string>
#include <vector>

using namespace std;

vector<int> adj[300001];
vector<int> cost;
int dp[300001][2];

void dfs(int cur)
{
    if (adj[cur].empty())
    {
        dp[cur][0] = 0;
        dp[cur][1] = cost[cur - 1];
    }
    else
    {
        int sum = 0;
        bool flag = false;
        int no = 0x7FFFFFFF;

        for (auto it : adj[cur])
        {
            dfs(it);
            if (dp[it][0] > dp[it][1])
            {
                sum += dp[it][1];
                flag = true;
            }
            else
            {
                sum += dp[it][0];
            }
            no = min(no, dp[it][1] - dp[it][0]);
        }
        if (!flag)
        {
            dp[cur][0] = sum + no;
        }
        else
            dp[cur][0] = sum;
        dp[cur][1] = sum + cost[cur - 1];
    }
}

int solution(vector<int> sales, vector<vector<int>> links)
{
    int answer = 0;
    cost = sales;

    for (int i = 0; i < links.size(); i++)
        adj[links[i][0]].push_back(links[i][1]);

    dfs(1);
    answer = min(dp[1][0], dp[1][1]);
    return answer;
}