//1476 - ��¥ ��� (Silver5, ����, ���Ʈ����, ������)
//E =15 , S = 28, M =19 �� ���� ���� 0���� �ٲ��ְ� ����
//�ݺ������� i%15 = E && i%28 = S && i%19 =M �� �ּ� year ã���� �� 

#include <iostream>
using namespace std;

#define MAX 10000

int main() {
    //�Է�
    int E, S, M;
    cin >> E >> S >> M;

    //����
    E %= 15; //�ִ밪�� �� 0�� �ǰ� ��
    S %= 28;
    M %= 19;

    int year = 0;
    for (int i = 1; i <= MAX; i++) {
        if (i % 15 == E && i % 28 == S && i % 19 == M) {
            year = i;   //if ������ �����ϸ� year = i;�� ������ break;(�ݺ� ����)
            break;
        }
    }

    //���
    cout << year;
}