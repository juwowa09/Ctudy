#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    while (cin >> input)
    {
        int n = stoi(input.substr(2));

        int count = 0;
        for (int x = n + 1; x <= 2 * n; ++x)
        {
            int y = x * n / (x - n);
            if (x * n == y * (x - n))
            {
                ++count;
            }
        }
        cout << count << endl;
    }
}