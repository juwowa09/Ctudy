#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = 0, sum = 0, st = 0, en = -1;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    while (en < n)
    {
        if (sum < m)
            sum += v[++en];
        else if (sum > m)
        {
            sum -= v[st++];
        }
        else
        {
            result++;
            sum -= v[st++];
        }
    }
    cout << result;
}