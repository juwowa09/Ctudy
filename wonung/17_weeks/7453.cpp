#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long result = 0;
int arr[4000][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];

    vector<int> one;
    vector<int> two;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            one.push_back(arr[i][0] + arr[j][1]);
            two.push_back(arr[i][2] + arr[j][3]);
        }

    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    for (auto it : one)
    {
        result += upper_bound(two.begin(), two.end(), -it) - lower_bound(two.begin(), two.end(), -it);
    }
    cout << result;
}