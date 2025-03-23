//19640 - 화장실의 규칙 (Gold4, 구횬, 자료 구조, 시뮬레이션, 우선순위 큐)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int idx;        // 처음 줄에 선 번호
    int line_num;   // m개의 줄 중 속한 줄의 번호
    int work_days;  // 근무 일수
    int urgency;    // 급한 정도
};

struct cmp {
    bool operator()(const info& child, const info& parent) {
        if (parent.work_days != child.work_days) {
            return parent.work_days > child.work_days;
        }
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency;
        }
        return parent.line_num < child.line_num;
    }
};

int simulation(int m, int k, vector<queue<info>>& lines) {
    // 각 줄의 선두들이 저장되는 우선순위 큐
    priority_queue<info, vector<info>, cmp> pq;

    // 우선순위 큐 초기화
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    // k 차례가 오기 전 화장실을 사용한 사람의 수
    int count = 0;

    while (!pq.empty() && pq.top().idx != k) {  // k의 차례가 되기 전까지
        int line_num = pq.top().line_num;
        pq.pop();

        if (!lines[line_num].empty()) {
            pq.push(lines[line_num].front());
            lines[line_num].pop();
        }

        count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m, queue<info>());

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        lines[i % m].push({ i, i % m, d, h });
    }

    // 연산 & 출력
    cout << simulation(m, k, lines);

    return 0;
}

