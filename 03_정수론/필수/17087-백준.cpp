#include <iostream>
#include <vector>

using namespace std;

int �ִ�����(int a, int b) { //a�� �� Ŀ�� ��
    if (b == 0) {
        return a;
    }
    return �ִ�����(b, a % b);
}

int ���ٲ���(int s, vector <int> v) {
    int result = v[0];
    for (int i = 1; i < v.size(); i++) {
        result = �ִ�����(result, v[i]);
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
    cout << ���ٲ���(s, v);
    return 0;
}