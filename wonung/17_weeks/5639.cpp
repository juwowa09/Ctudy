#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arr[10000];

void postorder(int st, int en)
{
    if (st == en)
        return;
    int mid = upper_bound(arr + st + 1, arr + en, arr[st]) - arr;
    postorder(st + 1, mid);
    postorder(mid, en);
    cout << arr[st] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 0;
    while (cin >> arr[k])
        k++;

    postorder(0, k);
}