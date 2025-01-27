#include <string>
#include <vector>

using namespace std;

int sum;
int num;
vector<int> v;

void dfs(int cur, int pos, int s, vector<int> v)
{
    if (s == sum && pos == num - 1)
    {
    }
}

vector<int> solution(int n, int s)
{
    vector<int> answer;
    num = n;
    sum = s;
    if (n > s)
        answer.resize(1, -1);
    else if (n == s)
    {
        answer.resize(n, 1);
    }
    else
    {
        int mod = s % n;

        for (int i = 0; i < n - mod; i++)
            answer.push_back(s / n);
        for (int i = 0; i < mod; i++)
            answer.push_back(s / n + 1);
    }
    return answer;
}