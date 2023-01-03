#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int qNum;
int space[16][16] = { 0 };
vector<int> qPos;

bool validation(int line) {
	for (int i = 0; i < qNum; i++) {
		if (space[line][i] == 0)
			return true;
	}
	return false;
}

void fill(int index) {
	int x = index % qNum;
	int y = index / qNum;

	for (int i = y+1; i < qNum; i++) {
		int diff = abs(y - i);
		if (x + diff < qNum) {
			space[i][x+diff]++;
		}
		if (x - diff >= 0) {
			space[i][x - diff]++;
		}
		space[i][x]++;
	}
	space[y][x]++;
}

void restore(int index) {
	int x = index % qNum;
	int y = index / qNum;

	for (int i = y+1; i < qNum; i++) {
		int diff = abs(y - i);
		if (x + diff < qNum) {
			space[i][x + diff]--;
		}
		if (x - diff >= 0) {
			space[i][x - diff]--;
		}
		space[i][x]--;
	}
	space[y][x]--;
}

int cal(int choiced) {
	if (choiced == qNum)
		return 1;
	if (!validation(choiced))
		return 0;

	int casenum = 0;
	for (int i = 0; i < qNum; i++) {
		if (space[choiced][i] == 0) {
			fill(choiced * qNum + i);
			casenum += cal(choiced + 1);
			restore(choiced * qNum + i);
		}
	}
	return casenum;
}

int main() {
	cin >> qNum;
	cout << cal(0);
}