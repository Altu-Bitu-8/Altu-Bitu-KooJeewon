#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;                          //명령의 수
    cin >> n;

    queue<int> q;                   //큐 선언

    string cmd;
    int x;

    //1부터 n까지 큐에 삽입
    for (int i = 1; i <= n; i++) {  
        q.push(i);
    }

    //마지막 한 장이 남을 때까지 반복
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    //마지막으로 남은 카드 출력
    cout << q.front() << endl;
    return 0;
}