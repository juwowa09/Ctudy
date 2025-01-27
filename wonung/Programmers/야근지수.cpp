#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    long long sum = 0;

    priority_queue<int, vector<int>, less<int>> pq;

    for (auto i : works)
        pq.push(i);

    while (n--)
    {
        if (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            f--;
            if (f)
                pq.push(f);
        }
    }
    while (!pq.empty())
    {
        sum += pq.top() * pq.top();
        pq.pop();
    }
    answer = sum;
    return answer;
}