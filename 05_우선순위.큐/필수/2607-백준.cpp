//2607 - ����� �ܾ� (Silver2, ����, ���ڿ�)
#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26;

 // �� ���ĺ��� ���� ����
vector<int> countFreq(string word) {
    vector<int> freq;
    for (int i = 0; i < word.length(); i++) {
        freq[word[i] - 'A']++;
    }
    return freq;
}

int countDiff(string word, vector<int>& original_freq) {
    vector<int> freq(NUM_CHARS, 0);
    int diff = 0; // ���� �ܾ���� ����

    // �� ���ĺ��� ���� ����
    countFreq(word, freq); 

    // ���� �ܾ�� �ٸ� ���ĺ� ���� ���ϱ�
    for (int i = 0; i < NUM_CHARS; i++) {
        diff += abs(original_freq[i] - freq[i]);
    }
    return diff;
}

int main() {
    int n, ans = 0;
    string original;

    // �Է�
    cin >> n >> original;
    vector<int> original_freq(NUM_CHARS, 0);

    // ����
    countFreq(original, original_freq);

    for (int i = 1; i < n; i++) {
        string word;
        cin >> word;

        int diff = countDiff(word, original_freq);
        // ����� �ܾ� ����
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            ans++;
        }
    }

    // ���
    cout << ans;
    return 0;
}