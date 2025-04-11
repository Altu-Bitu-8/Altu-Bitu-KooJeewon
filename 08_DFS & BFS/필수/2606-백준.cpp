//백준2606 - Silver3
//1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수? 
#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> graph;      //인접 리스트 그래프와 방문 체크 배열 선언
vector<bool> visited;

int count = 0;             // 1번 컴퓨터를 통해 감염된 컴퓨터 수

// DFS 함수: 현재 노드에서 인접 노드들을 탐색하며 감염 확산
void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            count++;        // 새로 감염된 컴퓨터 수 증가
            dfs(next);      // 재귀 호출로 연결된 컴퓨터 탐색
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 그래프와 방문 배열 크기 설정 (1번부터 시작하므로 n+1)
    graph.resize(n + 1);
    visited.resize(n + 1, false);

    // 네트워크 연결 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // 양방향 연결
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 1번 컴퓨터에서 DFS 시작
    dfs(1);

    // 1번을 제외한 감염된 컴퓨터 수 출력
    cout << count << endl;

    return 0;
}

