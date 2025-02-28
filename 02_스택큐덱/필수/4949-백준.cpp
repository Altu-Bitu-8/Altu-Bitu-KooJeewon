#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;

    for (char ch : str) {
        //왼쪽 괄호는 스택에 push
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        // 오른쪽 괄호는 스택에서 pop하여 검사
        else if (ch == ')') {
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
        }
        else if (ch == ']') {
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
    }
    
    //스택이 비어 있어야 균형잡힌 문자열 
    return s.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        getline(cin, str);
        if (str == ".") break;          // 종료 조건

        if (isBalanced(str)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}