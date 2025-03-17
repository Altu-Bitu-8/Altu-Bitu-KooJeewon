#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic;
const int ALPHA = 26;

//index���� �ð�������� ������ ������� ���ĺ� ���
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = "";
    //������ ���� ���� �ݴ�������� ���
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n];
    }
    return ans;
}

//����� ���� ��ȯ
string makeWheel(int n, int k, vector<ic>& record) {
    vector<char> wheel(n, '?'); //������ ��� ���ĺ��� ?�� �ʱ�ȭ
    vector<bool> is_available(ALPHA, false); // ���ĺ� �ߺ� üũ

    int index = 0; //ȭ��ǥ�� ����Ű�� �ε���

    for (int i = 0; i < k; i++) {
        int s = record[i].first; //ȭ��ǥ�� ����Ű�� ���ڰ� ���ϴ� Ƚ��
        char ch = record[i].second; //ȸ���� ���߾��� �� ����Ű�� ����

        index = (index + s) % n; //ȸ���� �� ȭ��ǥ�� ����Ű�� �ε���

        //�ش� ĭ�� ch�� �̹� ä���� �ִ� ��� �Ѿ
        if (wheel[index] == ch) {
            continue;
        }

        //�ٸ� ���ڷ� ä�����ְų� �ش� ���ڰ� �̹� ���� ���ĺ��� ��� ! ��ȯ
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch; //�ش� ĭ�� ���� ����
        is_available[ch - 'A'] = true; //�ش� ���ĺ��� ���Ǿ����Ƿ� true�� ����
    }
    return printWheel(n, index, wheel);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //�Է�
    int n, k;
    cin >> n >> k;

    vector<ic> record(k);
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    //���� & ���
    cout << makeWheel(n, k, record);

    return 0;
}