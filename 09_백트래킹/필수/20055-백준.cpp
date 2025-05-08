//����14888 - Silver1(��Ʈ��ŷ, ���Ʈ����)

//#include <iostream>
//#include <deque>

//using namespace std;
//
//struct info { // �� ĭ���� �������� �κ� ���� ���� ����
//    int power;
//    bool is_on = false;
//};

// ��Ʈ�� �� ĭ ȸ��
//void rotateBelt(deque<info>& belt, int n) {
//    belt.push_front(belt.back()); // ��Ʈ�� ������ ĭ�� �տ� push
//    belt.pop_back();              // ������ ĭ�� pop
//    belt[n - 1].is_on = false;    // �κ� ������
//}

// �κ��� ������ �� �ִٸ� �� ĭ �̵�
//void moveRobot(deque<info>& belt, int n) {
//    for (int i = n - 2; i >= 0; i--) { // �迭 ���� ���� ������ 0~n-1�ε� ���� ĭ�� ���ϱ� ���� 0~n-2���� �ݺ�
//        // ���� ĭ�� �κ��� �����ϰ�, ���� ĭ�� �κ��� ������, ���� ĭ�� �������� �������� �� �̵� ����
//        if (belt[i].is_on && !belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
//            belt[i].is_on = false;
//            belt[i + 1].is_on = true;
//            belt[i + 1].power--;
//        }
//    }
//    belt[n - 1].is_on = false; // �κ� ������
//}

// �ø��� ĭ�� �κ��� �ø� �� �ִٸ� �ø���
//void putRobot(deque<info>& belt) {
//    // �ø��� ĭ�� �������� ���� ������
//    if (belt[0].power >= 1) {
//        belt[0].is_on = true;
//        belt[0].power--;
//    }
//}

// ��Ʈ�� ������ üũ
//bool checkFinish(deque<info>& belt, int n, int k) {
//    int cnt = 0; // ������ 0�� ĭ�� ����
//    for (int i = 0; i < 2 * n; i++) {
//        if (belt[i].power == 0) {
//            cnt++;
//        }
//    }
//
//    return cnt >= k;
//}

//int solution(deque<info>& belt, int n, int k) {
//    // 1�ܰ���� ����
//    int step = 1;
//    while (true) {
//        // 1. ��Ʈ ȸ��
//        rotateBelt(belt, n);
//
//        // 2. �κ� �̵�
//        moveRobot(belt, n);
//
//        // 3. �κ� �ø���
//        putRobot(belt);
//
//        // 4. �������� 0�� ĭ�� ������ k�� �̻����� üũ
//        if (checkFinish(belt, n, k)) {
//            return step;
//        }
//        step++;
//    }
//}

//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    // �Է�
//    int n, k; // �����̾� ��Ʈ�� ����, ������ 0�� ĭ�� �ִ� ����
//    cin >> n >> k;
//    deque<info> belt(2 * n); // �����̾� ��Ʈ�� �������� �κ� ���� ���� ����
//
//    // ��Ʈ�� �� ĭ���� ������ �Է�, �κ� ���� ���� �ʱ�ȭ
//    for (int i = 0; i < 2 * n; i++)
//    {
//        cin >> belt[i].power;
//    }
//
//    // ���� & ���
//    cout << solution(belt, n, k);
//}