#include <iostream>
#include <algorithm>
using namespace std;

int bag[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, w, v;

    cin >> n >> k;

    while (n--)
    {
        cin >> w >> v;
        for (int j = k; j >= w; j--)
            bag[j] = max(bag[j], bag[j - w] + v);
    }
    cout << bag[k];
}