#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> words)
{
    int answer = 0;
    long sum = 0;
    sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++)
    {
        int cnt = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int j = 0; i - 1 >= 0 && j < words[i].size(); j++)
        {
            if (words[i][j] == words[i - 1][j])
                cnt1++;
            else
                break;
        }
        for (int j = 0; i + 1 < words.size() && j < words[i].size(); j++)
        {
            if (words[i][j] == words[i + 1][j])
                cnt2++;
            else
                break;
        }
        cnt = max(cnt1, cnt2);
        if (cnt < words[i].size())
            cnt++;
        sum += cnt;
    }
    answer = sum;
    return answer;
}