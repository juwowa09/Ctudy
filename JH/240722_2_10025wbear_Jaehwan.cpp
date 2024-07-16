#include <iostream>
#include <map>

using namespace std;

int n, k;
int g, x;


map<int, int> m; // 얼음에 비해 배열 크기 매우 크다 -> 해시? + 최대 최소 알기 위한 정렬 필요

int main() {

  cin >> n >> k;

  for (auto i = 0; i < n; i++) {
    cin >> g >> x;
    m[x] = g; // 얼음 양동이 있는 곳 g개, 없는 곳 0개
    
  }

  int x_min = m.begin()->first;
  int x_max = (--m.end())->first;
  int ans = 0;


  if (x_max - x_min < k * 2) {
    for (auto i = x_min; i <= x_max; i++){
      ans += m[i];
    }
  }

  else{
    for (auto i = x_min + k; i <= x_max - k; i++) {
    
      int temp = 0;
      for (auto j = -k; j <= k; j++){
        temp += m[i + j];
      }

      ans = max(ans, temp);
    }

  }

  cout << ans;  

}
/*

x_i에 N개 존재
양동이 g_i개 얼음존재
좌우 k까지 가능

양동이 모두 위치 다름

*/
