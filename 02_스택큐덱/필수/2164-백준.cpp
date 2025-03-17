#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;                          //����� ��
    cin >> n;

    queue<int> q;                   //ť ����

    string cmd;
    int x;

    //1���� n���� ť�� ����
    for (int i = 1; i <= n; i++) {  
        q.push(i);
    }

    //������ �� ���� ���� ������ �ݺ�
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    //���������� ���� ī�� ���
    cout << q.front() << endl;
    return 0;
}