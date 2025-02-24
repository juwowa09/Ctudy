// 누적합
#include <iostream>
using namespace std;

int n, h, result = 200001, cnt = 0;
int bottom[500001];
int top[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h;
    for (int i = 0; i < n / 2; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        bottom[a]++;
        top[b]++;
    }
    for (int i = h; i >= 1; i--)
    {
        top[i - 1] += top[i];
        bottom[i - 1] += bottom[i];
    }
    for (int i = 1; i <= h; i++)
    {
        result = min(result, top[h - (i - 1)] + bottom[i]);
    }
    for (int i = 1; i <= h; i++)
    {
        if (result == top[h - i + 1] + bottom[i])
            cnt++;
    }
    cout << result << " " << cnt;
}

// 이분탐색
#include <iostream>
#include <algorithm>
using namespace std;

int n, h, result = 200001, cnt = 0;
int bottom[500001];
int top[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h;
    for (int i = 0; i < n / 2; i++)
    {
        cin >> bottom[i];
        cin >> top[i];
    }
    sort(bottom, bottom + n / 2);
    sort(top, top + n / 2);

    for (int i = 1; i <= h; i++)
    {
        int a = lower_bound(bottom, bottom + n / 2, i) - bottom;
        int b = upper_bound(top, top + n / 2, h - i) - top;
        int br = n / 2 - a + n / 2 - b;
        if (br == result)
            cnt++;
        else if (br < result)
        {
            cnt = 1;
            result = br;
        }
    }
    cout << result << " " << cnt;
}