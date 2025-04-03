//����14002 - Gold4(���̳��� ���α׷���)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // �Է�
    int n, len;
    int max_len = 0;      // ���� LIS ����
    int max_idx = -1;     // LIS�� ������ ��ġ
    int a[1001], dp[1001];
    vector<int> arr;
    cin >> n;

    // ����
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                len = max(dp[j], len);
            }
        }
        dp[i] = len + 1;

        if (max_len < dp[i]) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    // ���������� �����ϸ� �κ� ���� ����
    for (int i = max_idx; i >= 0; i--) {
        if (max_len == dp[i]) {
            arr.push_back(a[i]);
            max_len--;
        }
    }

    // ���
    int size = arr.size();
    cout << size << "\n";

    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}