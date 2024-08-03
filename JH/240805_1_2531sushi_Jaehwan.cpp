#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    int N, d, k, c;
    int ans = 0;

    cin >> N >> d >> k >> c;

    vector<int> arr(N);

    for(auto i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    map<int, int> m;
    bool getc = false;

    for(auto i = 0; i < k; i++){
        m[arr[i]]++;
    }


    int kMax = m.size();
    if(m.find(c) == m.end()) getc = true;

    if(N > k){
        for(auto i = 1; i <= N; i++){
            m[arr[i - 1]]--;
            if (m[arr[i - 1]] == 0) m.erase(arr[i - 1]);

            if (i + k - 1 >= N) m[arr[i + k - 1 - N]]++;
            else m[arr[i + k - 1]]++;

            kMax = max(kMax, int(m.size()));
            if(m.find(c) == m.end()) getc = true;    
        }
    }

    if(!getc) ans = kMax;
    else ans = kMax + 1;

    cout << ans;

}