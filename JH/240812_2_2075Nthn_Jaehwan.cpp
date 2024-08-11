#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N;

    cin >> N;

    priority_queue<pair<int, int>> pq;
    vector<int> ind(N, N-1);

    vector<vector<int>> arr(N, vector<int>(N));

    int ans;

    for(auto i = 0; i < N; i++){
        for(auto j = 0; j < N; j++){
            cin >> arr[i][j];

            if(i == N - 1){
                pq.push({arr[i][j], j});
            }
        }
    }


    for(auto i = 0; i < N; i++){
        ans = pq.top().first;
        int tempx = pq.top().second;
        pq.pop();
        
        ind[tempx]--;
        
        if (ind[tempx] >= 0) {
            pq.push({arr[ind[tempx]][tempx], tempx});
        }
    }

    cout << ans;
}