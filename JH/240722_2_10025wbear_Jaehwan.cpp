#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int n, k;
int g, x;

queue<int> q;
unordered_map<int, int> um; // 얼음에 비해 배열 크기 매우 크다 -> 해시?

int main() {

  cin >> n >> k;

  for (auto i = 0; i < n; i++) {
    cin >> g >> x;
    um[x] = g; // 얼음 양동이 있는 곳 g개, 없는 곳 0개
    q.push(x); // 얼음 양동이 위치 입력
  }

  int ans = 0;

  while (!q.empty()) {
    int qf = q.front(); // 얼음 양동이 위치 qf

    for (auto i = qf - k; i <= qf + k; i++) { // 얼음 양동이 주변만 체크

      int temp = 0;
      for (auto j = -k; j <= k; j++) {
        temp += um[i + j]; // 얼음양동이 기준 -k부터 k까지 더하기
      }

      ans = max(temp, ans);
    }

    q.pop(); // qf 기준 계산 끝나면 제거
  }

  cout << ans;
}
/*

x_i에 N개 존재
양동이 g_i개 얼음존재
좌우 k까지 가능

양동이 모두 위치 다름

*/
