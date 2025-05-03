//����11726 - Silver3(���̳��� ���α׷���)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    //�Է�
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    //����
    dp[1] = 1;
    if (n >= 2) {
        dp[2] = 2;
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    //���  
    cout << dp[n];

    return 0;
}
