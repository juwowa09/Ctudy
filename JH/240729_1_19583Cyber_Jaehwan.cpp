#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

string s, e, q;
string sh, sm, eh, em, qh, qm; // 시와 분 분리
int ism, iem, iqm; // string 분리 후 int로 변환
string t, th, tm, id; // 각 id 접속 시각 시와 분 분리
int im;
string input, line1, line;

map<string, pair<bool, bool>> iMap; //  set이 더 좋은 선택지로 보임

int main(){
    getline(cin, line1);

    istringstream iss1(line1);
    if(iss1 >> s >> e >> q) {
        sh = s.substr(0, 2); // 콤마 제거
        sm = s.substr(3, 2); // 빈칸 제거
        ism = stoi(sh) * 60 + stoi(sm); // 시간 -> 분 으로 변환

        eh = e.substr(0, 2);
        em = e.substr(3, 2);
        iem = stoi(eh) * 60 + stoi(em);
        
        qh = q.substr(0, 2);
        qm = q.substr(3, 2);
        iqm = stoi(qh) * 60 + stoi(qm);
    }

    while (getline(cin, line)){
        if(line.empty()) { // 줄 비어있으면 break
            break;
        }

        istringstream iss2(line); // 동일하게 콤마, 빈칸, 분 변환
        if(iss2 >> t >> id){
            th = t.substr(0,2);
            tm = t.substr(3,2);
            im = stoi(th) * 60 + stoi(tm);

            if (im <= ism){
                iMap[id].first = true;
            } else if (im >= iem && im <= iqm){
                iMap[id].second = true;
            }
        }
    }

    int ans = 0;
    for(auto i : iMap){
        if (i.second.first && i.second.second){ // iMap의 두개의 bool이 모두 true이면 ans + 1
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}