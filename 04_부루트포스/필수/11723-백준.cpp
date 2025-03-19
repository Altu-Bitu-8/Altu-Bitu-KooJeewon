//11723 - ���� (Silver5, ��Ʈ����ŷ)
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //�Է�
    int M;
    cin >> M;

    //���� & ��� 
    int S = 0;
    for (int i = 0; i < M; i++) {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (cmd == "all") {
            S = (1 << 20) - 1;
        }
        else if (cmd == "empty") {
            S = 0;
        }
    }

    return 0;
}