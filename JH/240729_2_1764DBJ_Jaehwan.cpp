#include <iostream>
#include <map> // 사전순 출력을 위해 unordered_map 대신 채택
#include <string>

using namespace std;

int n, m;
map<string, int> aMap;

int dbj = 0;

int main(){
    cin >> n >> m;
    for(auto i = 0; i < n; i++){ // 듣지 못한 사람 n명
        string temp;
        cin >> temp;
        aMap[temp] += 1; // 중복되는 인원 없으므로 2번 이상 등장하면 듣보잡
    }

    for(auto i = 0; i < m; i++){ // 보지 못한 사람 m명
        string temp;
        cin >> temp;
        aMap[temp] += 1;
        if (aMap[temp] >= 2){ // 듣보잡 조건 = 듣지 못함 + 보지 못함 = 2
            dbj++;
        }
    }

    cout << dbj << '\n';

    for(auto i : aMap){ // map은 1번째 원소 기준 자동 오름차순 정렬
        if(i.second >= 2){
            cout << i.first << '\n'; // 사전순 출력
        }
    }

}