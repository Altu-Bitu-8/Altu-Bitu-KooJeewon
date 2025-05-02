//백준14888 - Silver1(백트래킹, 브루트포스)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;
int ops[4];  // +, -, *, /
int max_result = -1e9;
int min_result = 1e9;

void dfs(int idx, int result) {
    if (idx == N) {
        max_result = max(max_result, result);
        min_result = min(min_result, result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (ops[i] > 0) {
            ops[i]--;

            int next = result;
            if (i == 0) next += numbers[idx];
            else if (i == 1) next -= numbers[idx];
            else if (i == 2) next *= numbers[idx];
            else if (i == 3) {
                //음수 나눗셈 처리
                if (next < 0)
                    next = -(-next / numbers[idx]);
                else
                    next /= numbers[idx];
            }

            dfs(idx + 1, next);
            ops[i]++;  // 백트래킹
        }
    }
}

int main() {
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];
    for (int i = 0; i < 4; i++) cin >> ops[i];

    dfs(1, numbers[0]);

    cout << max_result << '\n' << min_result << '\n';
    return 0;
}

