#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;

    while (1)
    {
        int n, k;
        vector<string> pro;
        do
        {
            cin >> input;
            if (input == "NUM")
                continue;
            pro.push_back(input);
        } while (input != "END" && input != "QUIT");

        if (input == "QUIT")
            break;

        cin >> n;
        while (n--)
        {
            bool flag = true;
            cin >> k;
            stack<int> s;
            s.push(k);
            for (auto it : pro)
            {
                if (it == "POP")
                {
                    if (s.empty())
                    {
                        flag = false;
                        break;
                    }
                    else
                        s.pop();
                }
                else if (it == "INV")
                {
                    if (s.empty())
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        int t = s.top();
                        s.pop();
                        s.push(-1 * t);
                    }
                }
                else if (it == "DUP")
                {

                    if (s.empty())
                    {
                        flag = false;
                        break;
                    }
                    else
                        s.push(s.top());
                }
                else if (it == "SWP")
                {

                    if (s.size() < 2)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        int first = s.top();
                        s.pop();
                        int second = s.top();
                        s.pop();
                        s.push(first);
                        s.push(second);
                    }
                }
                else if (it == "ADD")
                {
                    if (s.size() < 2)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        long first = s.top();
                        s.pop();
                        long second = s.top();
                        s.pop();
                        if (abs(second + first) > 1000000000)
                        {
                            flag = false;
                            break;
                        }
                        s.push(second + first);
                    }
                }
                else if (it == "SUB")
                {
                    if (s.size() < 2)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        long first = s.top();
                        s.pop();
                        long second = s.top();
                        s.pop();
                        if (abs(second - first) > 1000000000)
                        {
                            flag = false;
                            break;
                        }
                        s.push(second - first);
                    }
                }
                else if (it == "MUL")
                {
                    if (s.size() < 2)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        long long first = s.top();
                        s.pop();
                        long long second = s.top();
                        s.pop();
                        if (abs(first * second) > 1000000000)
                        {
                            flag = false;
                            break;
                        }
                        s.push(first * second);
                    }
                }
                else if (it == "DIV")
                {
                    if (s.size() < 2)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        int first = s.top();
                        s.pop();
                        int second = s.top();
                        s.pop();
                        if (first == 0)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            int sign = 1;
                            if (second < 0)
                                sign *= -1;
                            if (first < 0)
                                sign *= -1;
                            s.push(sign * (abs(second) / abs(first)));
                        }
                    }
                }
                else if (it == "MOD")
                {
                    if (s.size() < 2)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        int first = s.top();
                        s.pop();
                        int second = s.top();
                        s.pop();
                        if (first == 0)
                        {
                            flag = false;
                            ;
                            break;
                        }
                        else
                        {
                            int sign = 1;
                            if (second < 0)
                                sign *= -1;
                            s.push(sign * (abs(second) % abs(first)));
                        }
                    }
                }
                else if (it == "END")
                    continue;
                else
                {
                    int num = 0;
                    for (int i = 0; i < it.size(); i++)
                        num = num * 10 + it[i] - 48;
                    s.push(num);
                }
            }
            if (!flag || s.size() != 1)
                cout << "ERROR\n";
            else
                cout << s.top() << "\n";
        }
        cout << "\n";
    }
}