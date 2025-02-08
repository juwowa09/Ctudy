#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Trie
{
    bool en;
    Trie *next[10];

    Trie()
    {
        en = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
    ~Trie()
    {
        en = false;
        for (int i = 0; i < 10; i++)
            if (next[i])
                delete next[i];
    }
    void insert(const char *key, bool *flag)
    {
        if (*key == '\0')
        {
            en = true;
            return;
        }
        else
        {
            if (en)
                *flag = false;
            int n = *key - '0';
            if (!next[n])
                next[n] = new Trie();

            next[n]->insert(key + 1, flag);
        }
    }
};

Trie *root;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0;

    cin >> t;

    while (t--)
    {
        int n;

        set<string> s;
        string str;

        if (root)
            delete root;

        root = new Trie();
        cin >> n;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            cin >> str;
            s.insert(str);
        }

        for (auto it : s)
        {
            if (!flag)
                break;
            root->insert(it.c_str(), &flag);
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
        s.clear();
    }
}