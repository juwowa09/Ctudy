#include <iostream>

using namespace std;

int n, k;
int g, x;
int arr[1000001];

int main(){
    cin >> n >> k;

    for (auto i = 0; i < n; i++){
        cin >> g >> x;
        arr[x] = g;
    }


    int sum = 0;
    int ans = 0;

    if (k >= 500000) {
        for(auto i = 0; i <= 1000000; i++){
            ans += arr[i];
        }
    }


    else{
        for (auto i = 0; i <= k * 2; i++){
            sum += arr[i];
        }

        ans = sum;

        for (auto i = k; i < 1000000 - k; i++){
            sum = sum + arr[i + k + 1] - arr[i - k];
            ans = max(ans, sum);
        }
    }
        

    cout << ans;


}
