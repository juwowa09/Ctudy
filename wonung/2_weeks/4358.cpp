#include <iostream>
#include <map>
#include <iomanip> // setprecision과 fixed를 사용하기 위해 필요

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> trees;
    int cnt = 0;
    string input;
    while (getline(cin, input))
    {
        if (input == "char")
            break;
        trees[input] += 1;
        cnt++;
    }
    for (map<string, int>::iterator it = trees.begin(); trees.end() != it; it++)
    {
        cout << it->first << ' ' << fixed << setprecision(4) << (double)it->second / cnt * 100 << '\n';
    }
}