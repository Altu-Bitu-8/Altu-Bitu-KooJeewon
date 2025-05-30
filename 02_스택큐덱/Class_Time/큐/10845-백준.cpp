//큐
//FIFO (First In First Out)
//자료의 왼쪽 끝 위치에서 삭제, 오른쪽 끝 위치에서 삽입 연산이 이루어짐.
//-> front에서 dequeue, rear에서 enqueue

//배열을 원형으로 되어있다고 생각하고 구현
//(Rear+1) % SIZE == Front : Full

//10845-백준 (큐/Silver4)
#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;                          //명령의 수
    cin >> n;

    vector<int> arr(MAX_SIZE);      //큐 선언
    int front = 0, rear = 0;        //front와 rear가 같은 곳을 바라보도록 초기화

    string cmd;
    int x;

    while (n--) {
        cin >> cmd;                 //명령 입력

        //push: 큐에 x 삽입
        if (cmd == "push") {
            cin >> x;
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = x;
        }

        //pop: 큐에서 front 원소 삭제하고 출력
        else if (cmd == "pop") {
            if (front == rear) {     //큐가 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                front = (front + 1) % MAX_SIZE;
                cout << arr[front] << "\n";
            }
        }

        //size: 큐의 크기 출력
        else if (cmd == "size") {
            cout << (rear - front) << "\n";
        }

        //empty: 큐가 비어있는지 확인
        else if (cmd == "empty") {
            cout << (front == rear) << "\n";
        }

        //front: 큐의 front 출력
        else if (cmd == "front") {
            if (front == rear) {        //큐가 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[(front + 1) % MAX_SIZE] << "\n";
            }
        }

        //back: 큐의 back 출력
        else if (cmd == "back") {
            if (front == rear) {        //큐가 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[rear] << "\n";
            }
        }
    }

    return 0;
}


