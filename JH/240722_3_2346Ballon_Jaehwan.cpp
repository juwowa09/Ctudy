#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

int n;
int x;

deque<pair<int, int>> dq;


int main(){
    cin >> n;


    for (auto i = 0; i < n; i++){
        cin >> x;
        dq.push_back(make_pair(i + 1, x));
    }

    while(!dq.empty()){
        int dqf = dq.front().second;
        cout << dq.front().first <<" ";
        dq.pop_front();

        if (dq.size() <= 1){
            cout << dq.front().first;
            dq.pop_front();
        }

        else if (dqf < 0){
            for (auto i = 0; i > dqf; i--){
                dq.push_front(dq.back());
                dq.pop_back();
            }


        }

        else{
            for (auto i = 1; i < dqf; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }


}



/*
3, 2, 1, -3, -1인 경우
1, 4, 5, 3, 2
*/