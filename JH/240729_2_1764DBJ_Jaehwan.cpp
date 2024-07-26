#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
map<string, int> aMap;

int dbj = 0;

int main(){
    cin >> n >> m;
    for(auto i = 0; i < n; i++){
        string temp;
        cin >> temp;
        aMap[temp] += 1;
    }

    for(auto i = 0; i < m; i++){
        string temp;
        cin >> temp;
        aMap[temp] += 1;
        if (aMap[temp] >= 2){
            dbj++;
        }
    }

    cout << dbj << '\n';

    for(auto i : aMap){
        if(i.second >= 2){
            cout << i.first << '\n';
        }
    }

}