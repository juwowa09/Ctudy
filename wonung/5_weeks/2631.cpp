#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 이진 탐색을 위한 dp 벡터
    vector<int> dp;

    for (int i = 0; i < n; i++)
    {
        // 현재 요소의 삽입 위치를 찾기 위해 이진 탐색 수행
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end())
        {
            dp.push_back(arr[i]); // 현재 요소가 가장 크면 끝에 추가
        }
        else
        {
            *it = arr[i]; // 아니면 위치에 덮어쓰기
        }
    }

    // 최장 증가 부분 수열의 길이는 dp의 크기
    int result = dp.size();
    cout << n - result;

    delete[] arr; // 동적 메모리 해제
    return 0;
}
