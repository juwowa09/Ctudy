#include <iostream>
#include <set>
#include <map> // 반대로 접근할 필요가 있을까?

using namespace std;

int N;
int arr[101];
set<int> setA, setB;


int main(){
    cin >> N;

    for (auto i = 1; i <= N; i++){ // 인덱스 0부터 시작했던 실수 정정
        cin >> arr[i];
        setA.insert(i);
        setB.insert(arr[i]);
    }

    while(setA != setB){ // set 비교연산 가능

        set<int> setTempA; // for문 안에서 setA 수정했던 실수 정정

        for (auto i : setA){
            if (setB.find(i) != setB.end()){
                setTempA.insert(i);
            }
        }

        setA = setTempA; // set 삽입연산 가능

        set<int> setTempB;

        for (auto i : setA){
            setTempB.insert(arr[i]);
        }

        setB = setTempB;
    }

    cout << setB.size() << '\n';

    for(auto i : setB){
        cout << i << '\n';
    }
}