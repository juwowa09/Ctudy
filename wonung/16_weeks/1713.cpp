#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int n, k, num;
map<int, pair<int, int>> pic;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> k;

    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> num;

        if (pic.find(num) != pic.end())
            pic[num].first++;
        else
        {
            if (pic.size() < n)
                pic[num] = {1, i};
            else
            {
                int rec = 10000;
                for (auto it : pic)
                {
                    if (rec > it.second.first)
                        rec = it.second.first;
                }
                vector<int> v;
                for (auto it : pic)
                {
                    if (rec == it.second.first)
                        v.push_back(it.first);
                }
                if (v.size() == 1)
                {
                    pic.erase(v[0]);
                    pic[num] = {1, i};
                }
                else
                {
                    int replace;
                    int time = 10000;
                    for (auto it : v)
                    {
                        if (time > pic[it].second)
                        {
                            time = pic[it].second;
                            replace = it;
                        }
                    }
                    pic.erase(replace);
                    pic[num] = {1, i};
                }
            }
        }
    }

    for (auto it : pic)
        cout << it.first << " ";
}