#include <iostream>
#include <map>
#include <iomanip> // setprecision과 fixed를 사용하기 위해 필요

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<char, int> m;
    int n, olen, ilen, size, result;
    string original, input;
    cin >> n;
    cin >> original;
    olen = original.length();
    for (int j = 0; j < olen; j++)
    {
        m[original[j]]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int diff_count = 0;
        map<char, int> temp = m;
        cin >> input;
        ilen = input.length();
        for (int j = 0; j < ilen; j++)
        {
            temp[input[j]]--;
        }
        for (map<char, int>::iterator it = temp.begin(); it != temp.end(); it++)
        {
            diff_count += abs(it->second);
        }
        if ((olen == ilen && diff_count <= 2) ||
            (olen == ilen + 1 && diff_count <= 1) ||
            (olen + 1 == ilen && diff_count <= 1))
        {
            result++;
        }
    }
    cout << result;
}