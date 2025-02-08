#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n;

struct Trie
{
    bool end;
    map<string, Trie *> m;

    Trie()
    {
        end = false;
    }
    ~Trie()
    {
        m.clear();
        end = false;
    }
    void insert(vector<string>::iterator it, vector<string>::iterator en)
    {
        if (it == en)
        {
            end = true;
        }
        else
        {
            if (m.find(*it) == m.end())
                m[*it] = new Trie();

            m[*it]->insert(it + 1, en);
        }
    }
};

void printTrie(Trie *node, int cnt)
{
    if (!node)
        return;
    for (auto it : node->m)
    {
        for (int i = 0; i < 2 * cnt; i++)
            cout << "-";
        cout << it.first << "\n";
        printTrie(it.second, cnt + 1);
    }
}

Trie *root;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    root = new Trie();

    for (int i = 0; i < n; i++)
    {
        int k;
        vector<string> v;
        cin >> k;
        while (k--)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        root->insert(v.begin(), v.end());
        v.clear();
        v.shrink_to_fit();
    }

    printTrie(root, 0);
}