#include <iostream>
#include <map> // 사전순 출력을 위해 unordered_map 대신 채택
#include <string>
#include <sstream>
#include <iomanip> // 반올림 헤더 파일

using namespace std;

map<string, double> treeMap;
double total;

int main(){
    string input, line;

    while (true){
        getline(cin, line); // 한 줄씩 입력받기
        if (line.empty()) {
            break; // 빈 줄을 입력하면 종료
        }

        treeMap[line] += 1.;
        total += 1.;
    }



    for (auto i : treeMap){
        double percentage = 0.;
        percentage = i.second * 100 / total;

        cout << i.first << ' ' << fixed << setprecision(4) << percentage << '\n';
    }

}