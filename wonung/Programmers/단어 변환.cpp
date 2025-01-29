#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, result = 0;
bool visited[50];
vector<string> w;

bool check(string pre, string cur)
{
    int count = 0;
    for (int i = 0; i < pre.size(); i++)
    {
        if (pre[i] != cur[i])
            count++;
    }
    if (count == 1)
        return true;
    return false;
}

void bfs(string begin, string target)
{
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        if (f.first == target)
        {
            result = f.second;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            if (check(w[i], f.first))
            {
                visited[i] = true;
                q.push({w[i], f.second + 1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    n = words.size();
    w = words;

    bfs(begin, target);
    return result;
}

// DFS

#include <string>
#include <vector>

using namespace std;

int n, result = 51;
bool visited[51];
string t;
vector<string> w;

void dfs(int pos, string pre, int cnt)
{
    int count = 0;

    for (int j = 0; j < pre.size(); j++)
    {
        if (w[pos][j] != pre[j])
            count++;
    }

    if (count == 1)
    {
        if (w[pos] == t)
        {
            result = min(result, cnt + 1);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (pos == i || visited[i])
                continue;

            visited[i] = true;
            dfs(i, w[pos], cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    n = words.size();
    w = words;
    t = target;

    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i, begin, 0);
        visited[i] = false;
    }
    if (result == 51)
        return 0;
    return result;
}
