#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

map<string, int> m;
map<string, priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                cmp>>
    ms;

priority_queue<pair<int, string>, vector<pair<int, string>>, less<pair<int, string>>> pq;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    for (int i = 0; i < plays.size(); i++)
    {
        m[genres[i]] += plays[i];
        ms[genres[i]].push({plays[i], i});
    }
    for (auto it : m)
    {
        pq.push({it.second, it.first});
    }
    vector<int> answer;

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        for (int i = 0; i < 2; i++)
        {
            if (!ms[f.second].empty())
            {
                answer.push_back(ms[f.second].top().second);
                ms[f.second].pop();
            }
        }
    }
    return answer;
}