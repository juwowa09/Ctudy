#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (b[0] == a[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int time = 0;
    int cnt = 0;

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

    sort(jobs.begin(), jobs.end());

    while ((jobs.size() != cnt) && pq.empty())
    {
        bool flag = false;
        if (pq.empty())
        {
            for (int i = cnt; i < jobs.size(); i++)
            {
                if (time >= jobs[i][0])
                {
                    pq.push({{jobs[i][1], jobs[i][0]}, i});
                    cnt++;
                    flag = true;
                }
                else
                    break;
            }
            if (!flag)
            {
                time = jobs[cnt][0];
                pq.push({{jobs[cnt][1], jobs[cnt][0]}, cnt});
                cnt++;
            }
        }

        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            time += f.first.first;

            for (int i = cnt; i < jobs.size(); i++)
            {
                if (time >= jobs[i][0])
                {
                    pq.push({{jobs[i][1], jobs[i][0]}, i});
                    cnt++;
                }
            }
            answer += time - f.first.second;
        }
    }
    answer /= jobs.size();
    return answer;
}