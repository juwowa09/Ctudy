#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int n, k;
int g, x;

queue<int> q;
unordered_map<int, int> um;

int main(){
    cin >> n >> k;
    
    for (auto i = 0; i < n; i++){
        cin >> g >> x;
        um[x] = g;
        q.push(x);
    }

    int ans = 0;

    while(!q.empty()){
        int qf = q.front();
        int temp = 0;

        for(auto i = qf - k; i <= qf + k; i++){
            for(auto j = -k; j <= k; j++){
                temp += um[i + j];
            }
        }

        ans = max(temp, ans);
    }

    cout << ans;





}
/*

x_i에 N개 존재
양동이 g_i개 얼음존재
좌우 k까지 가능

양동이 모두 위치 다름

*/