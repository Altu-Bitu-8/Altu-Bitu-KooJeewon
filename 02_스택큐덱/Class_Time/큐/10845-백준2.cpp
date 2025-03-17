//10845-���� (ť/Silver4)
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

    while (n--) {
        cin >> cmd;                 //��� �Է�

        //push: ť�� x ����
        if (cmd == "push") {
            cin >> x;
            q.push(x);
        }

        //pop: ť���� front ���� �����ϰ� ���
        else if (cmd == "pop") {
            if (q.empty()) {        //ť�� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        //size: ť�� ũ�� ���
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }

        //empty: ť�� ����ִ��� Ȯ��
        else if (cmd == "empty") {
            cout << q.empty() << "\n";
        }

        //front: ť�� front ���
        else if (cmd == "front") {
            if (q.empty()) {        //ť�� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }

        //back: ť�� back ���
        else if (cmd == "back") {
            if (q.empty()) {        //ť�� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}
