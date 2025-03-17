//10866-���� (��/Silver4)
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //����� ��
    cin >> n;

    deque<int> dq; //�� ����

    string cmd;
    int x;

    while (n--) {
        cin >> cmd; //��� �Է�

        //push_front: ���� front�� x ����
        if (cmd == "push_front") {
            cin >> x;
            dq.push_front(x);
        }

        //push_back: ���� back�� x ����
        else if (cmd == "push_back") {
            cin >> x;
            dq.push_back(x);
        }

        //pop_front: ������ front ���� �����ϰ� ���
        else if (cmd == "pop_front") {
            if (dq.empty()) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }

        //pop_back: ������ back ���� �����ϰ� ���
        else if (cmd == "pop_back") {
            if (dq.empty()) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }

        //size: ���� ũ�� ���
        else if (cmd == "size") {
            cout << dq.size() << "\n";
        }

        //empty: ���� ����ִ��� Ȯ��
        else if (cmd == "empty") {
            cout << dq.empty() << "\n";
        }

        //front: ���� front ���
        else if (cmd == "front") {
            if (dq.empty()) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
            }
        }

        //back: ���� back ���
        else if (cmd == "back") {
            if (dq.empty()) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
            }
        }
    }

    return 0;
}
