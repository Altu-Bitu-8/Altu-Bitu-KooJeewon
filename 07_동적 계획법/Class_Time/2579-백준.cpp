//백준2579 - Silver3(다이나믹 프로그래밍)
#include <iostream>
#include <vector>

using namespace std;

int getMaxScore(int n, vector<int>& score) {
    //dp[i]: i번째 계단까지 왔을 ?? 점수의 최댓값
    vector<int> dp(n + 1, 0);

    //초깃값
    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    //점화식
    for (int i = 3; i <= n; i++) {
        //세 칸을 연속으로 밟을 수 없으므로 
        int one_step_before = dp[i - 3] + score[i - 1];
        int two_step_before = dp[i - 2];
        dp[i] = max(one_step_before, two_step_before) + score[i];
    }
    return dp[n];
}

int main() {
    //입력
    int n;
    cin >> n;
    vector<int> score(n + 1, 0);

    //score[i] 일때이게 i번째 금액이길 바래서
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    //연산
    int answer = getMaxScore(n, score);

    //출력
    cout << answer;

    return 0;
}