//백준11053 - Silver2(다이나믹 프로그래밍)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //입력
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //연산
    vector<int> dp(N, 1); // 각 원소를 끝으로 하는 LIS 길이 초기화 (1)

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    //출력
    int result = *max_element(dp.begin(), dp.end());
    cout << result << '\n';

    return 0;
}

