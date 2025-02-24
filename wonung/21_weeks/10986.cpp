#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n, k;
long long result = 0;
vector<long long> arr;
unordered_map<long long, int> Map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] % k == 0)
            result++;
        result += Map[arr[i] % k];
        Map[arr[i] % k]++;
    }
    cout << result;
}