#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string start_, end_, streamEnd, time, name;
    int cnt = 0;
    set<string> s;

    cin >> start_ >> end_ >> streamEnd;
    //    while (cin >> input)
    //    {
    //        ss.clear();
    //        ss.str(input);
    //        ss >> key >> value;
    //        if (strcmp(key.c_str(), start_.c_str()) <= 0)
    //        {
    //            m[key] = value;
    //        }
    //        else if (strcmp(key.c_str(), end_.c_str()) >= 0 &&
    //                 strcmp(key.c_str(), streamEnd.c_str()) <= 0 &&
    //                 !strcmp(m[key].c_str(), value.c_str()))
    //        {
    //            cout<<m[key].c_str()<<'\n';
    //            cnt++;
    //        }
    //        if (!strcmp(input.c_str(), "char"))
    //            cout << cnt << '\n';
    //    }
    while (cin >> time >> name)
    {
        if (time <= start_)
            s.insert(name);
        else if (time >= end_ &&
                 time <= streamEnd &&
                 (s.find(name) != s.end()))
        {
            s.erase(name);
            cnt++;
        }
    }
    cout << cnt << '\n';
}