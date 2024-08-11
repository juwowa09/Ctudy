#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int ans;

int main(){
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N));
    vector<int> vinit(N, N-1);
    vector<int> vMax(N);


    for(auto i = 0; i < N; i++){
        for (auto j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }


    for (int i = 0; i < N; i++) {
        vMax[i] = arr[N-1][i];
    }


    for (auto k = 0; k < N; k++){
        auto temp_it = max_element(vMax.begin(), vMax.end());
        int ind = temp_it - vMax.begin();
        ans = *temp_it;


        vinit[ind]--;
        if (vinit[ind] >= 0) {
            vMax[ind] = arr[vinit[ind]][ind];
        } else {
            vMax[ind] = -2e9;
        }
    }

    cout << ans;
}