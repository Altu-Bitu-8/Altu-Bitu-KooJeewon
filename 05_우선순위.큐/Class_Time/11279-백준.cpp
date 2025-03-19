//11279 - �ִ� �� (Silver2, �ڷ� ����, �켱���� ť)
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // �Է�
    int n, x;
    priority_queue<int> max_heap;
    cin >> n;

    // ���� & ���
    while (n--) {
        cin >> x;

        // x�� 0�� ��� max_heap���� ���� ū �� ���
        if (x == 0) {
            // max_heap�� ����ִ� ��� 0 ���
            if (max_heap.empty()) {
                cout << "0\n";
            }
            else {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
        }
        // x�� �ڿ����� ��� max_heap�� x ����
        else {
            max_heap.push(x);
        }
    }

    return 0;
}