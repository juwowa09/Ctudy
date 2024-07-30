#include <iostream>
#include <set>

using namespace std;

int N, d, k, c;
int arr[30000]; // vector 이용해서 find?
int ans;
bool noSushi;



int main(){
    cin >> N >> d >> k >> c;


    for(auto i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(auto i = 0; i < N; i++){
        if (arr[i] == c){
            if(i <= N - k){

                set<int> s;
                s.insert(c);
                for (auto j = 1; j < k; j++){
                    s.insert(arr[i+j]);
                    if(arr[i+j] == c) noSushi = true;
                }.

                int sSize = s.size();
                
                ans = max(ans, sSize);
            }

            else{

                set<int> s;
                s.insert(c);
                for (auto j = i + 1; j < N; j++){
                    s.insert(arr[j]);
                    if(arr[j] == c) noSushi = true;
                }
                for (auto j = 0; j < i - N + k; j++){
                    if(arr[j] == c) noSushi = true;
                    s.insert(arr[j]);
                }

                int sSize = s.size();

                ans = max(ans, sSize);
            }
        }

        else{
            if(i <= N - k){

                set<int> s;
                for (auto j = 0; j < k; j++){
                    s.insert(arr[i+j]);
                }

                int sSize = s.size();

                ans = max(ans, sSize);
            }

            else{

                set<int> s;
                for (auto j = i; j < N; j++){
                    s.insert(arr[j]);
                }
                for (auto j = 0; j < i - N + k; j++){
                    s.insert(arr[j]);

                }

                int sSize = s.size();

                ans = max(ans, sSize);
            }
        }
    }

    if (noSushi){
        cout << ans;
    }

    else{
        cout << ans + 1;
    }

    
}

/*
k <= n, c <= d
*/