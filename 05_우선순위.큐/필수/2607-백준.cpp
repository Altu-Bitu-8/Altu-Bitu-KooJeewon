//2607 - ����� �ܾ� (Silver2, ����, ���ڿ�)
#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //�Է�
    int n, x; //x: �Է¹��� ���ڸ� �����ϴ� ����
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > min_heap; // �ּ� �� ���(greater<int>)


    //���� & ���
    for (int i = 0; i < n * n; i++) {
        cin >> x;
        if (min_heap.size() < n) {
            min_heap.push(x); //�ٷ� push(x)[���� �߰�/ n���� �������]
        }
        else if (min_heap.top() < x) {
            min_heap.pop(); //����
            min_heap.push(x); //���ο� x�� �߰�
        }
    }

    cout << min_heap.top() << "\n"; //N��°�� ū �� ���
    return 0;
}