#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N;

    cin >> N;

    vector<vector<int>> arr(N, vector<int> (N));
    map<int, int> m;

    vector<int> cnt(N, 0);

    int ans;

    for(auto i = 0; i < N; i++){
        for(auto j = 0; j < N; j++){
            cin >> arr[i][j];

            if(i == N - 1){
                m[-arr[i][j]] = j;
            }
        }
    }

    for(auto i = 1; i <= N; i++){
        if (i == N){
            cout << -m.begin()->first;
            return 0;
        }
        int tempf = m.begin()->first;
        int temps = m.begin()->second;
        cnt[temps]++;
        m[-arr[N - 1 - cnt[temps]][temps]] = temps;
        m.erase(tempf);
    }
}