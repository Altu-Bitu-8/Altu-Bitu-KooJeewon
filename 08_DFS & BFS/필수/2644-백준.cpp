//����2644 - Silver2
//�ִܰŸ� ���� --> BFS�� Ǯ�� 
#include <iostream>
#include <vector>

using namespace std;

int n, a, b, m;
vector<vector<int>> graph;   // ���� ����Ʈ (��� ���� ����)
vector<int> visited;         // �� �������� �̼� ����

// BFS�� ����� �ִ� �̼��� ���
int bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = 0; // ���� ����� �̼��� 0

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // ��ǥ ��忡 �������� ��� �̼� ��ȯ
        if (now == target) return visited[now];

        // ���� ��忡 ����� ��� ��� Ž��
        for (int next : graph[now]) {
            // �湮���� ���� ����� ���
            if (visited[next] == -1) {
                visited[next] = visited[now] + 1; // �̼� ���
                q.push(next);
            }
        }
    }

    // ������� �ʾ��� ���
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;      // ��� ��
    cin >> a >> b; // �̼� ��� ���
    cin >> m;      // ���� ��

    graph.resize(n + 1);        // ��� ��ȣ�� 1������
    visited.assign(n + 1, -1);  // �ʱⰪ -1 (�湮 ����)

    // ���� �Է� (����� �׷����� ����)
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // BFS ���� ��� ���
    cout << bfs(a, b) << '\n';

    return 0;
}
