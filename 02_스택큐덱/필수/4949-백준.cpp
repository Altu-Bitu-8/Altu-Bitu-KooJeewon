#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;

    for (char ch : str) {
        //���� ��ȣ�� ���ÿ� push
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        // ������ ��ȣ�� ���ÿ��� pop�Ͽ� �˻�
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
    
    //������ ��� �־�� �������� ���ڿ� 
    return s.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        getline(cin, str);
        if (str == ".") break;          // ���� ����

        if (isBalanced(str)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}