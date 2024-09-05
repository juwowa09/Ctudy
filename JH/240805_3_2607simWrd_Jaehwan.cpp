#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;
string word1;
int ans = 0;
map<char, int> m1;
vector<map<char, int>> marr(100);


vector<string> wordarr(100);

int main(){
    cin >> n;
    cin >> word1;

    for(auto i = 0; i < word1.size(); i++){
        m1[word1[i]]++;
    }

    for (auto i = 0; i < n - 1; i++){
        cin >> wordarr[i];
        if (wordarr[i].size() >= word1.size() - 1 && wordarr[i].size() <= word1.size() + 1){
            for(auto j = 0; j < wordarr[i].size(); j++){
                marr[i][wordarr[i][j]]++;
            }


            if (wordarr[i].size() == word1.size() - 1){
                int temp = 0;
                for(auto j : m1){
                    if (marr[i][j.first] == j.second - 1) temp++;
                }
                
                if(temp == 1) ans++;
            }

            else if (wordarr[i].size() == word1.size() + 1){
                int temp = 0;
                for(auto j : marr[i]){
                    if (m1[j.first] == j.second - 1) temp++;
                }

                if(temp == 1) ans++;
            }

            else {
                int temp = 0;
                bool eq = true;
                for(auto j : m1){
                    if (marr[i][j.first] == j.second - 1) temp++;
                    else if (marr[i][j.first] != j.second + 1 && marr[i][j.first] != j.second) eq = false;
                }

                if(eq && temp <= 1) ans++;
            }
        }
    }
    

    cout << ans;
}

/*

dolt
doll

l은 2개
t는 0개
제대로 정리할 것!!!

dolt
doab

l은 0개
t는 0개

dll
dllt


*/