#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int arr[2][100002];

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int g = 0; g < 2; g++)
            for (int j = 2; j <= n + 1; j++)
                cin >> arr[g][j];

        for (int j = 2; j <= n + 1; j++)
        {
            arr[0][j] = max(arr[1][j - 2], arr[1][j - 1]) + arr[0][j];
            arr[1][j] = max(arr[0][j - 2], arr[0][j - 1]) + arr[1][j];
        }
        cout << max(arr[0][n + 1], arr[1][n + 1]) << '\n';
    }
}