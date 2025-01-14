#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> prob;
vector<vector<int>> adj;
int n;

void topological()
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        if (prob[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int f = q.top();
        q.pop();

        for (vector<int>::iterator it = adj[f].begin(); it != adj[f].end(); it++)
        {
            prob[*it]--;
            if (prob[*it] == 0)
                q.push(*it);
        }
        cout << f << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, a, b;
    cin >> n >> m;
    prob.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        prob[b]++;
        adj[a].push_back(b);
    }
    topological();
}