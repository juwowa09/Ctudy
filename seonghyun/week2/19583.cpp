#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

string S, E, Q;
set<string> arr;
set<string>::iterator iter;
int answer = 0;


void input(){
    cin >> S >> E >> Q;
}

//시계열 데이터를 10진수로 바꾸기
int timeToDec(string time){
    int hour, minutes;
    hour = (time[0] - '0') * 10 + (time[1] - '0');
    minutes = (time[3] - '0') * 10 + (time[4] - '0');
    int result = hour*60 + minutes;

    return result;
}

bool isExisted(string name){
    iter = arr.find(name);
    if(iter == arr.end()) return false;
    
    return true;
}


void inputValue(string name){
    if(!isExisted(name)){
        arr.insert(name);
    }
}

void process(string time, string name){
    int startTime = timeToDec(S);
    int endTime = timeToDec(E);
    int streamingTime = timeToDec(Q);
    int realTime = timeToDec(time);

    // case 1 : 개강총회를 시작하기 전에
    if(realTime <= startTime){
        inputValue(name);
    }
    else{
        if(endTime <= realTime && realTime <= streamingTime){
            if(isExisted(name)) {
                arr.erase(iter);
                answer++;
            }
        }
    }
}

void sol(){
    string time, name;
    while(cin >> time >> name){
        if(time == "end") break;
        process(time, name);
    }

    cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();
    
    return 0;
}