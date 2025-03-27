//백준17451 (Silver3/그리디,수학)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;   //행성 갯수 입력 받음
    cin >> n;

    //최소 속도를 저장 
    vector<long long> v(n);   
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //마지막 행성에서 요구하는 속도가 v[n-1]
    long long speed = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (speed % v[i] != 0) {
            speed = ((speed / v[i]) + 1) * v[i];
        }
    }

    cout << speed << endl;
    return 0;
}

