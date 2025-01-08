#include <iostream>
#include <vector>
using namespace std;
long long result = 0;

vector<int> arr;
vector<int> v;

void merge(int st, int en)
{
    int mid = (en + st) / 2;
    if (st != en)
    {
        merge(st, mid);
        merge(mid + 1, en);
    }
    int i = st;
    int j = mid + 1;
    int k = st;
    while (i <= mid && j <= en)
    {
        if (arr[i] > arr[j])
        {
            v[k] = arr[j];
            result += j - k; //  자신의 자리를 찾아감. 내 앞에 나보다 큰 수가 몇개
                             // 있는 지 누적 해가며 알 수 있다.
            j++;
        }
        else
        {
            v[k] = arr[i];
            i++;
        }
        k++;
    }
    while (k <= en)
    {
        if (i <= mid)
        {
            v[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            v[k] = arr[j];
            k++;
            j++;
        }
    }
    while (st <= en)
    {
        arr[st] = v[st];
        st++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge(0, n - 1);
    cout << result;
}