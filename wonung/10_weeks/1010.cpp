#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, result = 1, n, m;

    cin >> t;
    while (t--)
    {
        result = 1;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            result *= m - n + i;
            result /= i;
        }
        cout << result << "\n";
    }
}