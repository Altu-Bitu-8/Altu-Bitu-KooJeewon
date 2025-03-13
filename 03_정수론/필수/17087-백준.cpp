#include <iostream>
#include <vector>

using namespace std;

int 최대공약수(int a, int b) { //a가 더 커야 됨
    if (b == 0) {
        return a;
    }
    return 최대공약수(b, a % b);
}

int 숨바꼭질(int s, vector <int> v) {
    int result = v[0];
    for (int i = 1; i < v.size(); i++) {
        result = 최대공약수(result, v[i]);
    }
    return result;
}
int main() {
    int n, s;
    cin >> n >> s;
    vector <int> v(n);
    while (n--) {
        int a;
        cin >> a;
        v.push_back(abs(s - a));
    }
    cout << 숨바꼭질(s, v);
    return 0;
}