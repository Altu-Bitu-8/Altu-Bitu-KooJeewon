//-��-
//Douvle-Ended Queue
//�ڷ��� �� ������ ������ �̷���� 



//10866-���� (��/Silver4)
#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //����� ��
    cin >> n;

    vector<int> arr(MAX_SIZE); //�� ����
    int front = 0, back = 0;

    string cmd;
    int x;

    while (n--) {
        cin >> cmd; //��� �Է�

        //push_front: ���� front�� x ����
        if (cmd == "push_front") {
            cin >> x;
            front = (front + 1) % MAX_SIZE;
            arr[front] = x;
        }

        //push_back: ���� back�� x ����
        else if (cmd == "push_back") {
            cin >> x;
            arr[back] = x;
            back = (back - 1 + MAX_SIZE) % MAX_SIZE;
        }

        //pop_front: ������ front ���� �����ϰ� ���
        else if (cmd == "pop_front") {
            if (front == back) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[front] << "\n";
                front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            }
        }

        //pop_back: ������ back ���� �����ϰ� ���
        else if (cmd == "pop_back") {
            if (front == back) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                back = (back + 1) % MAX_SIZE;
                cout << arr[back] << "\n";
            }
        }

        //size: ���� ũ�� ���
        else if (cmd == "size") {
            cout << (front + MAX_SIZE - back) % MAX_SIZE << "\n";
        }

        //empty: ���� ����ִ��� Ȯ��
        else if (cmd == "empty") {
            cout << (front == back) << "\n";
        }

        //front: ���� front ���
        else if (cmd == "front") {
            if (front == back) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[front] << "\n";
            }
        }

        //back: ���� back ���
        else if (cmd == "back") {
            if (front == back) { //���� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[(back + 1) % MAX_SIZE] << "\n";
            }
        }
    }

    return 0;
}
