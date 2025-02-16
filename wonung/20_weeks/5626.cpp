#include <iostream>
#include <vector>
#define MAX 1000000007
using namespace std;

int n, m;
vector<int> cur(5002);
vector<int> pre(5002);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cur.resize(n / 2 + 1);
    pre.resize(n / 2 + 1);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k > min(i, n - i - 1))
        {
            cout << 0;
            return 0;
        }
        if (i == 0)
        {
            cur[0] = 1;
            pre[0] = 1;
        }
        else
        {
            if (k == -1)
            {
                for (int j = 0; j <= min(i, n - 1 - i); j++)
                {
                    cur[j] = (pre[j] + pre[j + 1]) % MAX;
                    if (j != 0)
                        cur[j] = (cur[j] + pre[j - 1]) % MAX;
                }
            }
            else
            {
                fill(cur.begin(), cur.end(), 0);
                cur[k] = (pre[k] + pre[k + 1]) % MAX;
                if (k != 0)
                    cur[k] = (cur[k] + pre[k - 1]) % MAX;
            }
            pre = cur;
        }
    }
    cout << cur[0];
}