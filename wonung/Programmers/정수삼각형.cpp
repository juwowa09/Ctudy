#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[500][500];
int result = 0;

int solution(vector<vector<int>> triangle)
{
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == triangle[i].size() - 1)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            result = max(result, dp[i][j]);
        }
    }
    return result;
}