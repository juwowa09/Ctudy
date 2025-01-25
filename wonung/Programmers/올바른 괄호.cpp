#include<string>
#include <iostream>
#include <stack>
using namespace std;

stack<char>st;

bool solution(string s)
{
    bool answer = true;
    
    for(char c : s)
    {
        if(st.empty() && c == ')')
            return false;
        if(c == '(')
            st.push('(');
        else if(c == ')')
            st.pop();
    }
    if(!st.empty())
        answer = false;
    
    return answer;
}