//2231 - 분해합 (Bronze2, 브루트포스)
#include <iostream>
using namespace std;

int bruteforce(int n) {
    for (int i = 1; i < n; i++) {
        int sum = i; //분해합 저장 
        int temp = i; //나머지를 담는 장소 

        while (temp) {
            sum += temp % 10; //temp의 1의 자리수를 sum에 추가 
            temp /= 10;

        }
        if (sum == n) {
            return i;
        }
    }
    return 0;
}

int main() {
    //입력
    int n;
    cin >> n;

    //연산
    int ans = bruteforce(n);

    //출력
    cout << ans;
}

