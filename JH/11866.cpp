#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q, answer;


int main(){

    cin >> n >> k;

    for (auto i = 0; i < n; i++){
        q.push(i + 1);
    }


    cout << "< ";
    
    while(!q.empty()){
        for (auto i = 0; i < k - 1; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        cout << q.front() << ", ";
        q.pop();
        
    }

    cout << ">";


}


/*
1, K, N 마지막 제거
K = 3일때 1 2 3 / 4 5 6 / 7 1 2 / 4 5 7 / 1 4 5 / 1 4 1 / 4 4 4
<3, 6, 2, 7, 5, 1, 4>
*/
