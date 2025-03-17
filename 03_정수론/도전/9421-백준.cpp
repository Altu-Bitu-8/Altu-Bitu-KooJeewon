//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// �Ҽ� ���� ��ȯ: �����佺�׳׽��� ü �̿�
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    return is_prime;
}

// �� �ڸ����� ������ �� ���
int getSum(int n) {
    int total = 0, tmp;
    while (n != 0) {
        tmp = n % 10;  // ���� ������ �ڸ� ���� ����
        total += tmp * tmp;
        n /= 10;  // ���� ������ �ڸ� ���� ���ֱ�
    }
    return total;
}

// ��ټ� ���� ��ȯ
bool checkValid(int n) {
    set<int> visited;  // ���ݱ��� ���� ���� �����ϴ� ����
    visited.insert(n);

    while (true) {
        n = getSum(n);  // �� �ڸ��� ������ �� ���ϱ�

        if (n == 1) {
            return true;
        }

        // ������ ���� ���� �ִ� ���̸� ��ټ� �ƴ�
        if (visited.find(n) != visited.end()) {
            return false;
        }
        visited.insert(n);
    }
}

int main() {
    // �Է�
    int n;
    cin >> n;

    // ���� & ���
    vector<bool> is_prime = getPrimes(n);

    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && checkValid(i)) {
            cout << i << '\n';
        }
    }

    return 0;
}