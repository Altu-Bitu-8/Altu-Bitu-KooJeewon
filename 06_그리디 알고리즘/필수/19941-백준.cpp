//백준19941 - 햄버거 분배 (Silver3/그리디)
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string table;
    cin >> table;

    int count = 0;

    for (int i = 0; i < N; ++i) {
        // 사람을 찾았을 때
        if (table[i] == 'P') {  
            // 왼쪽 범위부터 확인
            for (int j = max(0, i - K); j <= min(N - 1, i + K); ++j) {
                if (table[j] == 'H') {  // 햄버거를 찾으면
                    // 해당 햄버거를 먹음 처리
                    table[j] = '.';  
                    ++count;  // 먹은 사람 수 증가
                    break;  // 현재 사람에 대한 탐색 종료
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
