#include <iostream>
#include <queue>
#include <set>

using namespace std;


int N, d, k, c;

queue<int> q;
int ans;

int main(){
    cin >> N >> d >> k >> c;

    for(auto i = 0; i < N; i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }

    int kMax = 0;
    bool get_c = false;
    bool check_k = true;
    for(auto i = 0; i < N; i++){
        queue<int> tempq = q;
        set<int> temps;
        bool is_c = true;
    
        if(check_k){
            for(auto j = 0; j < k; j++){
                
                int qfront = tempq.front();
                temps.insert(qfront);
                tempq.pop();
                tempq.push(qfront);
            }
        }

        tempq = q;

        if(!get_c && q.front() == c){
            bool is_c = false;
            int qfront = tempq.front();
            tempq.pop();
            tempq.push(c);

            for(auto j = 1; j < k; j++){
                
                int qfront = tempq.front();
                if (qfront == c) is_c = true; break;
                tempq.pop();
                tempq.push(qfront);
            }

        }





        if(check_k){
            kMax = max(kMax, int(temps.size()));
        }

        
        if (kMax == k) check_k = false;
        if (is_c == false) get_c = true;

        if(!check_k && get_c) break;

        int qfront = q.front();
        q.pop();
        q.push(qfront);
    }

    if (get_c == true) ans = kMax + 1;
    else ans = kMax;

    cout << ans;

}