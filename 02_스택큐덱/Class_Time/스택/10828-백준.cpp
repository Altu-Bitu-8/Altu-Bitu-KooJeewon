//10828-���� (����/Silver4)
#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);      //C++�� ǥ�� ����� �ӵ��� ������ �ϱ����� ����
    cin.tie(NULL); cout.tie(NULL);    //cin�� cout�� ������ Ǯ�� ����� �ӵ��� ���

    int n;                            //����� ��
    cin >> n;

    vector<int> arr(MAX_SIZE);        //���� ����
    int top = -1;

    string cmd;
    int x;

    //��ɾ� ó�� ����
    while (n--) {                     
        cin >> cmd;                   //��� �Է�

        //push: ���ÿ� x ����
        if (cmd == "push") {
            cin >> x;
            arr[++top] = x;           //top�� 1 ������Ű��, �ش���ġ�� x����
        }

        //pop: ���ÿ��� top ���� �����ϰ� ���
        else if (cmd == "pop") {
            if (top == -1) {          //������ ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[top--] << "\n";
            }
        }

        //size: ������ ũ�� ���
        else if (cmd == "size") {
            cout << top + 1 << "\n";
        }

        //empty: ������ ����ִ��� Ȯ��
        else if (cmd == "empty") {
            cout << (top == -1) << "\n";
        }

        //top: ������ top ���(�� ���� ���� ���)
        else if (cmd == "top") {
            if (top == -1) {           //������ ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[top] << "\n";
            }
        }
    }

    return 0;
}