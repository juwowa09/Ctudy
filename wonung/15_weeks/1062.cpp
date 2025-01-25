#include <iostream>
#include <vector>
using namespace std;

int n, k, result = 0;
vector<int> v;

int word[50];

void dfs(int cur, int value, int cnt)
{
    if (cnt == k)
    {
        int count = 0;
        for (auto i : v)
        {
            if ((i & value) == i)
                count++;
        }
        result = max(result, count);
        return;
    }

    if (cur >= 26)
        return;

    if (!(value & (1 << cur)))
        dfs(cur + 1, value + (1 << cur), cnt + 1);
    dfs(cur + 1, value, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int cnt = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (!(word[i] & (1 << str[j] - 97)))
            {
                word[i] |= (1 << str[j] - 97);
                cnt++;
            }
        }
        if (cnt <= k)
            v.push_back(word[i]);
    }

    int check = (1 << ('a' - 97)) + (1 << ('c' - 97)) + (1 << ('t' - 97)) + (1 << ('n' - 97)) + (1 << ('i' - 97));
    dfs(0, check, 5);

    cout << result;
}