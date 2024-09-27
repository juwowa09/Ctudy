#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[50000];
    int n, x, cnt = 0;
    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] == arr[i])
                break;
            if (arr[j] < arr[i])
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}