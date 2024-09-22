#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    int n, y, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> y;
        while (!s.empty() && s.top() > y)
            s.pop();
        if ((s.empty() || s.top() < y) && y != 0)
        {
            cnt++;
            s.push(y);
        }
    }
    cout << cnt;
}