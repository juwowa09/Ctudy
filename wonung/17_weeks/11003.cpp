#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, l;
int arr[5000000];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int st = 0;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        pq.push({arr[i], i});
        q.push(arr[i]);

        if (q.size() > l)
        {
            st++;
            q.pop();
            while (pq.top().second < st)
                pq.pop();
        }

        cout << pq.top().first << " ";
    }
}