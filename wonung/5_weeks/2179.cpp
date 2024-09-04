#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt, result = 0, first, second;
    vector<string> v;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cnt = 0;
            if (v[i] == v[j])
                break;
            for (int k = 0; k < v[i].length(); k++)
            {
                if (cnt == k && v[i][k] && v[j][k] && (v[i][k] == v[j][k]))
                    cnt++;
            }
            if (result < cnt)
            {
                result = cnt;
                first = i;
                second = j;
            }
        }
    }
    cout << v[first] << '\n'
         << v[second];
}
