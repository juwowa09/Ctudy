#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000

int N, r, c;
int matrix[501][2], dp[501][501];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> r >> c;
        matrix[i][0] = r;
        matrix[i][1] = c;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j + i <= N; j++)
        {
            dp[j][j + i] = INF;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j],
                                   dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }
    cout << dp[1][N];
}