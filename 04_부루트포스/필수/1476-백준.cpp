//1476 - 날짜 계산 (Silver5, 수학, 브루트포스, 정수론)
//E =15 , S = 28, M =19 일 때만 각각 0으로 바꿔주고 시작
//반복문에서 i%15 = E && i%28 = S && i%19 =M 인 최소 year 찾으면 됨 

#include <iostream>
using namespace std;

#define MAX 10000

int main() {
    //입력
    int E, S, M;
    cin >> E >> S >> M;

    //연산
    E %= 15; //최대값일 때 0이 되게 함
    S %= 28;
    M %= 19;

    int year = 0;
    for (int i = 1; i <= MAX; i++) {
        if (i % 15 == E && i % 28 == S && i % 19 == M) {
            year = i;   //if 조건을 만족하면 year = i;에 저장후 break;(반복 종료)
            break;
        }
    }

    //출력
    cout << year;
}