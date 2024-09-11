#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int result = 0, flag, cnt = 1;
    stack<char> s;
    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(' || input[i] == '[')
        {
            flag = 1;
            s.push(input[i]);
            if (input[i] == '(')
                cnt *= 2;
            else
                cnt *= 3;
        }
        else if (input[i] == ')')
        {
            // segfault error solv empty
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            else if (flag == 1)
            {
                // 결과에 적용
                result += cnt;
                cnt /= 2;
                flag = 0;
            }
            else
                cnt /= 2;
            s.pop();
        }
        else if (input[i] == ']')
        {
            // segfault error solv empty
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
            }
            else if (flag == 1)
            {
                result += cnt;
                cnt /= 3;
                flag = 0;
            }
            else
                cnt /= 3;
            s.pop();
        }
    }
    // ((((( 열려있는 경우로 끝날 때 에러 해결
    if (!s.empty())
        cout << 0;
    else
        cout << result;
}