#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, result = 0;
int arr[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            int a = i, b = j;
            arr[i][j] = str[j - 1] - '0';
            if (arr[i][j])
            {
                arr[i][j] = min(min(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1]) + 1;
                result = max(result, arr[i][j]);
            }
        }
    }
    cout << result * result;
}