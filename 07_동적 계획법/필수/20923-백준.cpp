//����20923 - Silver1(�ڷᱸ��, ��, ����, �ùķ��̼�)
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;  // 0: ����, 1: ����
const int DO = 0, SU = 1;

// �¸� �Ǵ��ϱ� 
string judge(cards& deck) {
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();
	if (do_deck > su_deck) {
		return "do";
	}
	else if (do_deck < su_deck) {
		return "su";
	}
	return "dosu";
}

// �׶��忡�� ������ ī�� �ű�� 
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) {
		deck.push_back(ground.back());
		ground.pop_back();
	}
}

// ���� ���� �� 
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]);// ī�� �������� (��� �׶��� -> ���� ��)
	groundToDeck(deck[player], ground[player]); // ī�� �������� (���� �׶��� -> ���� ��)
}


// ���� �︱ �� �ִ� ��� �Ǵ� 
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // ����
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // ����
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // ����
		return SU;
	}
	return -1; // ���� �︱ �� ����
}

// ���� ���� 
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // ���� ����
	while (m--) {
		ground[turn].push_front(deck[turn].front()); // ī�� ��������(�� -> �׶���)
		deck[turn].pop_front();
		if (deck[turn].empty()) {
			break;
		}

		int bell = whoCanRingTheBell(deck, ground); // ���� �︱ �� �ִ� ���
		if (bell != -1) { // ���� �︰ ���
			ringTheBell(bell, deck, ground);
		}
		turn = !turn; // ���� �ٲٱ�
	}
	return judge(deck);
}


int main() {
	int n, m, card1, card2;
	cards deck(2), ground(2); // 0: ����, 1: ����

	// �Է�
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2;
		deck[DO].push_front(card1);
		deck[SU].push_front(card2);
	}

	// ��� & ����
	cout << game(m, deck, ground);

	return 0;
}