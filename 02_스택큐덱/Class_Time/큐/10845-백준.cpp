//ť
//FIFO (First In First Out)
//�ڷ��� ���� �� ��ġ���� ����, ������ �� ��ġ���� ���� ������ �̷����.
//-> front���� dequeue, rear���� enqueue

//�迭�� �������� �Ǿ��ִٰ� �����ϰ� ����
//(Rear+1) % SIZE == Front : Full

//10845-���� (ť/Silver4)
#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;                          //����� ��
    cin >> n;

    vector<int> arr(MAX_SIZE);      //ť ����
    int front = 0, rear = 0;        //front�� rear�� ���� ���� �ٶ󺸵��� �ʱ�ȭ

    string cmd;
    int x;

    while (n--) {
        cin >> cmd;                 //��� �Է�

        //push: ť�� x ����
        if (cmd == "push") {
            cin >> x;
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = x;
        }

        //pop: ť���� front ���� �����ϰ� ���
        else if (cmd == "pop") {
            if (front == rear) {     //ť�� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                front = (front + 1) % MAX_SIZE;
                cout << arr[front] << "\n";
            }
        }

        //size: ť�� ũ�� ���
        else if (cmd == "size") {
            cout << (rear - front) << "\n";
        }

        //empty: ť�� ����ִ��� Ȯ��
        else if (cmd == "empty") {
            cout << (front == rear) << "\n";
        }

        //front: ť�� front ���
        else if (cmd == "front") {
            if (front == rear) {        //ť�� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[(front + 1) % MAX_SIZE] << "\n";
            }
        }

        //back: ť�� back ���
        else if (cmd == "back") {
            if (front == rear) {        //ť�� ��� ���� �� -1 ����
                cout << "-1\n";
            }
            else {
                cout << arr[rear] << "\n";
            }
        }
    }

    return 0;
}


