//2607 - 비슷한 단어 (Silver2, 구현, 문자열)
#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, x; //x: 입력받을 숫자를 저장하는 변수
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > min_heap; // 최소 힙 사용(greater<int>)


    //연산 & 출력
    for (int i = 0; i < n * n; i++) {
        cin >> x;
        if (min_heap.size() < n) {
            min_heap.push(x); //바로 push(x)[값을 추가/ n개로 만들려고]
        }
        else if (min_heap.top() < x) {
            min_heap.pop(); //제거
            min_heap.push(x); //새로운 x를 추가
        }
    }

    cout << min_heap.top() << "\n"; //N번째로 큰 수 출력
    return 0;
}