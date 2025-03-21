//11286 - �ִ� �� (Silver1, �ڷ� ����, �켱���� ť)
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int& child, const int& parent) {
        // 1. ������ �ٸ� ��� ������ ���� ���� �θ����
        if (abs(parent) != abs(child)) {
            return abs(parent) < abs(child);
        }
        // 2. ������ ���� ��� ���� ���� ���� �θ����
        return parent < child;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // �Է�
    int n, x;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;

    // ���� & ���
    while (n--) {
        cin >> x;

        // x�� 0�� ��� ������ ���� ���� �� ���
        if (x == 0) {
            // pq�� ����ִ� ��� 0 ���
            if (pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        // x�� 0�� �ƴ� ��� pq�� x ����
        else {
            pq.push(x);
        }
    }

    return 0;
}