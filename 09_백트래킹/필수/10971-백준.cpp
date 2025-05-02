//����10971 - Silver2(��Ʈ��ŷ, ���Ʈ����)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int W[10][10];
int answer = 1e9;

int main() {
    cin >> N;
    vector<int> city(N);
    for (int i = 0; i < N; i++) city[i] = i;

    // ��� ��� �Է�
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    do {
        int cost = 0;                 //�̹� ������ �� ���
        bool valid = true;
        for (int i = 0; i < N - 1; i++) {
            // �� �� ���� ���
            if (W[city[i]][city[i + 1]] == 0) {
                valid = false;
                break;
            }
            cost += W[city[i]][city[i + 1]];
        }
        if (valid && W[city[N - 1]][city[0]] != 0) {
            // ��ȯ �Ϸ�
            cost += W[city[N - 1]][city[0]];
            answer = min(answer, cost);
        }

    } while (next_permutation(city.begin(), city.end()));

    cout << answer << '\n';
    return 0;
}



