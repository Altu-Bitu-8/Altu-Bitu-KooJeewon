//2607 - 비슷한 단어 (Silver2, 구현, 문자열)
#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26;

 // 각 알파벳의 개수 세기
vector<int> countFreq(string word) {
    vector<int> freq;
    for (int i = 0; i < word.length(); i++) {
        freq[word[i] - 'A']++;
    }
    return freq;
}

int countDiff(string word, vector<int>& original_freq) {
    vector<int> freq(NUM_CHARS, 0);
    int diff = 0; // 원본 단어와의 차이

    // 각 알파벳의 개수 세기
    countFreq(word, freq); 

    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {
        diff += abs(original_freq[i] - freq[i]);
    }
    return diff;
}

int main() {
    int n, ans = 0;
    string original;

    // 입력
    cin >> n >> original;
    vector<int> original_freq(NUM_CHARS, 0);

    // 연산
    countFreq(original, original_freq);

    for (int i = 1; i < n; i++) {
        string word;
        cin >> word;

        int diff = countDiff(word, original_freq);
        // 비슷한 단어 세기
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            ans++;
        }
    }

    // 출력
    cout << ans;
    return 0;
}