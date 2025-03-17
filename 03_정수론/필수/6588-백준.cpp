#include <stdio.h>
#include <iostream>

using namespace std;

const int MAX_N = 1000000;
bool arr[MAX_N + 1]; // ���� �迭 ��� (�޸� ���� ����)

void che() {
    arr[0] = arr[1] = true; // 0�� 1�� �Ҽ��� �ƴ�
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!arr[i]) { // �Ҽ����
            for (int j = i * i; j <= MAX_N; j += i) {
                arr[j] = true; // �Ҽ��� �ƴ� ������ ��ŷ
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    che(); // �Ҽ� ��ó��

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;

        bool hasAns = false; // ?? �Է¸��� �ʱ�ȭ�ؾ� ��

        for (int i = 3; i < n; i += 2) {
            if (!arr[i] && !arr[n - i]) {
                hasAns = true;
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }

        if (!hasAns)
            printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}