#include <iostream>
#include <deque>
#include <string>

using namespace std;

string addBigNumbers(string x, string y) {
    deque<int> d1, d2, result;
    int carry = 0;
    string sumResult = "";

    // 문자열을 숫자로 변환하여 덱에 저장
    for (char ch : x) d1.push_back(ch - '0');
    for (char ch : y) d2.push_back(ch - '0');

    // 두 덱을 이용하여 덧셈 수행 (뒤에서부터)
    while (!d1.empty() || !d2.empty() || carry) {
        int num1 = (d1.empty() ? 0 : d1.back()); // d1의 마지막 숫자
        int num2 = (d2.empty() ? 0 : d2.back()); // d2의 마지막 숫자

        if (!d1.empty()) d1.pop_back();
        if (!d2.empty()) d2.pop_back();

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        result.push_front(sum % 10); // 앞쪽으로 삽입 (자리 올림 반영)
    }

    // 결과 덱을 문자열로 변환
    for (int num : result) sumResult += (num + '0');

    return sumResult;
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << addBigNumbers(x, y) << "\n";
    return 0;
}
