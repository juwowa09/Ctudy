#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k, result = 0, sum = 0, num;
    cin >> n >> k;
    map<long, long> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        sum += num;
        if (sum == k)
            result++;
        if (m.find(sum - k) != m.end())
        {
            result += m[sum - k]; // 누적합이므로 map 에는 현재 앞에 존재하는 누적합에 대한 정보만 들어있음.
        }
        m[sum]++;
        //       result += m[v[i]-k]; k 가 0 인 경우 m[v[i]]++ 먼저하면 안됨.
    }
    cout << result;
}