//10828-���� (����/Silver4)
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;                          //����� ��
    cin >> n;

    stack<int> s;                   //���� ����

    string cmd;
    int x;

    while (n--) {
        cin >> cmd;                 //��� �Է�

        //push: ���ÿ� x ����
        if (cmd == "push") {
            cin >> x;
            s.push(x);
        }

        //pop: ���ÿ��� top ���� �����ϰ� ���
        else if (cmd == "pop") {
            if (s.empty()) {         //������ ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }

        //size: ������ ũ�� ���
        else if (cmd == "size") {
            cout << s.size() << "\n";
        }

        //empty: ������ ����ִ��� Ȯ��
        else if (cmd == "empty") {
            cout << s.empty() << "\n";
        }

        //top: ������ top ���
        else if (cmd == "top") {
            if (s.empty()) {          //������ ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}