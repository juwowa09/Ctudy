#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    long long result = 1;

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        result *= n - i + 1;
        result /= i;
    }

    cout << result;
}