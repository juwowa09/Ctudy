#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int main(){

    int N, M;
    
    map<string, bool> m;

    cin >> N >> M;

    vector<string> keyW(N);
    vector<string> writeW(M);

    cin.ignore();

    for(auto i = 0; i < N; i++){
        getline(cin, keyW[i]);
        m[keyW[i]] = true;
    }

    
    for(auto i = 0; i < M; i++){
        getline(cin, writeW[i]);
        string word;
        stringstream ss(writeW[i]);
        while(getline(ss, word, ',')){
            m.erase(word);
        }

        int ans = m.size();

        cout << ans << '\n';
    }
}