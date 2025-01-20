#include <iostream>
#include <vector>
using namespace std;

int n, k, result = 0;
;
unsigned int check[50];
vector<unsigned int> v;

void dfs(int num, int index, unsigned int value)
{
    if (num <= 0)
    {
        int cnt = 0;
        for (auto i : v)
        {
            if ((i & value) == i)
                cnt++;
        }
        result = max(result, cnt);
        return;
    }
    for (int i = index; i < 26; i++)
    {
        if (!(value & (1 << i)))
        {
            dfs(num - 1, i + 1, value |= (1 << i));
            value &= ~(1 << i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long check_bit = 0;
    string str;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            if (!(check[i] & 1 << (str[j] - 97)))
            {
                check[i] |= 1 << (str[j] - 97);
                cnt++;
            }
        if (cnt <= k)
            v.push_back(check[i]);
    }

    check_bit |= 1 << ('a' - 97);
    check_bit |= 1 << ('n' - 97);
    check_bit |= 1 << ('i' - 97);
    check_bit |= 1 << ('t' - 97);
    check_bit |= 1 << ('c' - 97);

    dfs(k - 5, 0, check_bit);
    cout << result;
}