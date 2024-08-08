#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    string input;
    unordered_set<string> s;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        s.insert(input);
    }
    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        int start = 0;
        int end = input.find(',', start);
        do
        {
            string word = input.substr(start, end - start);
            if (s.find(word) != s.end())
                s.erase(word);
            start = end + 1;
            end = input.find(',', start);
        } while (end != string::npos);
        s.erase(input.substr(start, input.length() - start));
        cout << s.size() << '\n';
    }
}