//백준11726 - Silver3(다이나믹 프로그래밍)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    //입력
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    //연산
    dp[1] = 1;
    if (n >= 2) {
        dp[2] = 2;
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    //출력  
    cout << dp[n];

    return 0;
}
