#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define endl '\n'
using namespace std;

//접시의 수 : N
//초밥의 가짓수 : d
//연속해서 먹는 접시의 개수 : k
//쿠폰번호 : c
int N, d, k ,c;
vector<int> belt;
map<int,int> m;

void input(){
    cin >> N >> d >> k >> c;
    int sushi;
    for(int i = 0; i < N; i++){
        cin >> sushi;
        belt.push_back(sushi);
    }
}

/*
흠 벡터와 인덱스를 통해 원형 리스트를 구현한다.
그리고 모든 경우의 수를 모두 해보고 그 중에서 max를 찾는다.
초밥의 종류 d가 주어졌으므로, 초기 배열을 선언하고 bool을 통해 이미 먹은 초밥인지 계산한다.
but 배운 set을 이용하면 더 쉽게할 수 있을 거 같음.

따라서 벡터로 전체적인 벨트를 만들고 브루트 포스와 set을 이용하여 max를 찾는다.

시간초과 발생
process 과정에서 시간초과가 발생한다.

슬라이싱 위도우 개념으로 생각해야할듯.
map을 통해서 같은 종류의 초밥이 들어있을 때 해당 초밥이 모두 빠지지 않게
해당 초밥의 갯수를 같이 저장한다.
*/


//슬라이싱 윈도우로 초밥이 포함되고 제거되는 과정
int process(int nextSushi, int lastSushi){
    m[nextSushi] += 1;

    if(m[lastSushi] == 1) m.erase(lastSushi);
    else m[lastSushi] -= 1; //초밥의 개수가 0이면 삭제해주어야함
    return m.size();
}

void sol(){
    
    m[c] = 1; //최대는 쿠폰을 활용한 경우

    //init
    for(int i = 0; i < k; i++){
        m[belt[i]] += 1;
    }
    int answer = m.size();
    int nextSushi, lastSushi;

    for(int i = k; i < N; i++){
        nextSushi = belt[i];
        lastSushi = belt[i-k];
        answer = max(answer, process(nextSushi, lastSushi));
        
    }
    //남은 바퀴
    for(int i = 0; i < k; i++){
        nextSushi = belt[i];
        lastSushi = belt[N+i-k];
        answer = max(answer, process(nextSushi, lastSushi));
    }

    cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();

    return 0;
}