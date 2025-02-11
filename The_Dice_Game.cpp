#include <iostream>
using namespace std;
void draw(int n) {
	switch (n) {
	case 1:
		cout << "@@@@@@@" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@@@ @@@" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 2:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@@@" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@@@@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 3:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@@@" << endl;
		cout << "@@@ @@@" << endl;
		cout << "@@@@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 4:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 5:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@ @@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 6:
		cout << "@@@@@@@" << endl;
		cout << "@ @ @ @" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@ @ @ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	}
	cout << endl;
}
int dieceThrow() {
	return rand() % 6 + 1;
}
int playerTurn() {
	//int a, b;
	//a = dieceThrow();
	// 
	//b = dieceThrow();
	int sum = 0;
	int t;
	cout << "Number draw:\n";
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int res = dieceThrow();
		sum += res;
		draw(res);
	}
	return sum;
}
void Output(int player, int comp)
{
	cout << "Score player: " << player << '\n';
	cout << "Score computer: " << comp << '\n';
}
void Victory(int player, int comp) {
	if (player > comp)
		cout << "Congratulation! Player wins." << '\n';
	else
		if (player == comp)
			cout << "Draw!";
		else
			cout << "Congratulation! Computer wins." << '\n';
	Output(player, comp);
}
bool choose()
{
	return rand() % 2;
}
int main()
{
	int y = 1;
	while (y == 1) {
		srand(time(NULL));
		int countplayer = 0;
		int countcomp = 0;
		bool player = choose();
		if (player)
			cout << "Player first" << endl;
		else
			cout << "Computer First" << endl;
		int n;
		cout << endl;
		cout << "Number rounds:\n";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; ++i) { /*количество раундов*/
			for (int j = 0; j < 2; ++j) { /*количество игроков*/
				if (player) {
					cout << "Are you ready?" << endl;
					char temp;
					cin >> temp;
					cout << endl;
					countplayer += playerTurn();
				}
				else
					countcomp += playerTurn();
				player = !player; /*переключатель игроков*/
			}
			Output(countplayer, countcomp);

		}
		Victory(countplayer, countcomp);
	}
}