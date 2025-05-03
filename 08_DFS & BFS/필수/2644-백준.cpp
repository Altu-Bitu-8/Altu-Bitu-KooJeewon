//백준2644 - Silver2
//최단거리 문제 --> BFS로 풀기 
#include <iostream>
#include <vector>

using namespace std;

int n, a, b, m;
vector<vector<int>> graph;   // 인접 리스트 (사람 관계 저장)
vector<int> visited;         // 각 노드까지의 촌수 저장

// BFS를 사용해 최단 촌수를 계산
int bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = 0; // 시작 노드의 촌수는 0

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 목표 노드에 도달했을 경우 촌수 반환
        if (now == target) return visited[now];

        // 현재 노드에 연결된 모든 사람 탐색
        for (int next : graph[now]) {
            // 방문하지 않은 사람일 경우
            if (visited[next] == -1) {
                visited[next] = visited[now] + 1; // 촌수 계산
                q.push(next);
            }
        }
    }

    // 연결되지 않았을 경우
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;      // 사람 수
    cin >> a >> b; // 촌수 계산 대상
    cin >> m;      // 관계 수

    graph.resize(n + 1);        // 사람 번호는 1번부터
    visited.assign(n + 1, -1);  // 초기값 -1 (방문 안함)

    // 관계 입력 (양방향 그래프로 저장)
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // BFS 실행 결과 출력
    cout << bfs(a, b) << '\n';

    return 0;
}
