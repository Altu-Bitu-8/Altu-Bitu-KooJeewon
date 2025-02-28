//10828-백준 (스택/Silver4)
#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);      //C++의 표준 입출력 속도를 빠르게 하기위한 설정
    cin.tie(NULL); cout.tie(NULL);    //cin과 cout의 묶음을 풀어 입출력 속도를 향상

    int n;                            //명령의 수
    cin >> n;

    vector<int> arr(MAX_SIZE);        //스택 선언
    int top = -1;

    string cmd;
    int x;

    //명령어 처리 루프
    while (n--) {                     
        cin >> cmd;                   //명령 입력

        //push: 스택에 x 삽입
        if (cmd == "push") {
            cin >> x;
            arr[++top] = x;           //top을 1 증가시키고, 해당위치에 x저장
        }

        //pop: 스택에서 top 원소 삭제하고 출력
        else if (cmd == "pop") {
            if (top == -1) {          //스택이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[top--] << "\n";
            }
        }

        //size: 스택의 크기 출력
        else if (cmd == "size") {
            cout << top + 1 << "\n";
        }

        //empty: 스택이 비어있는지 확인
        else if (cmd == "empty") {
            cout << (top == -1) << "\n";
        }

        //top: 스택의 top 출력(맨 위의 정수 출력)
        else if (cmd == "top") {
            if (top == -1) {           //스택이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[top] << "\n";
            }
        }
    }

    return 0;
}