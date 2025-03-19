//2231 - ������ (Bronze2, ���Ʈ����)
#include <iostream>
using namespace std;

int bruteforce(int n) {
    for (int i = 1; i < n; i++) {
        int sum = i; //������ ���� 
        int temp = i; //�������� ��� ��� 

        while (temp) {
            sum += temp % 10; //temp�� 1�� �ڸ����� sum�� �߰� 
            temp /= 10;

        }
        if (sum == n) {
            return i;
        }
    }
    return 0;
}

int main() {
    //�Է�
    int n;
    cin >> n;

    //����
    int ans = bruteforce(n);

    //���
    cout << ans;
}

