#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;


int main(){
    cin >> n >> k;

    for (auto i = 0; i < n; i++){
        q.push(i + 1); // 큐 1~7 순서대로 넣기
    }


    cout << "<";

    while(!q.empty()){
        for (auto i = 0; i < k - 1; i++){ // k-1번 반복
            int temp = q.front(); // temp에 q 앞에 있는 값 대입 (초기 : 1)
            q.pop(); // q 앞에 있는 temp 제거
            q.push(temp); // temp 다시 뒤로 push
        }


        if (q.size() == 1){ // 마지막 숫자일 경우 콤마 제거
            cout << q.front();
            q.pop();
        }

        else{
        cout << q.front() << ", "; // k번째 값 출력
        q.pop(); // 해당 값 제거
        }
    }

    cout << ">";


}


/*
1, K, N 마지막 제거
K = 3일때 1 2 3 / 4 5 6 / 7 1 2 / 4 5 7 / 1 4 5 / 1 4 1 / 4 4 4
<3, 6, 2, 7, 5, 1, 4>
*/
