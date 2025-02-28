#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100000];
vector<int> lcs;

int binary_s(int st, int en, int v)
{
    while (st < en)
    {
        int mid = st + (en - st) / 2;
        if (arr[mid].first == v)
            return arr[mid].second;
        else if (arr[mid].first > v)
            en = mid;
        else
            st = mid + 1;
    }
    return arr[en].second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int first_pos = binary_s(0, n - 1, a);
        if (lcs.empty())
            lcs.push_back(first_pos);
        else
        {
            int second_pos = lower_bound(lcs.begin(), lcs.end(), first_pos) - lcs.begin();
            if (second_pos == lcs.size())
                lcs.push_back(first_pos);
            else
                lcs[second_pos] = first_pos;
        }
    }
    cout << lcs.size();
}