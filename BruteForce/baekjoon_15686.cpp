#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int lenList[13][100];
vector<int> selected_c;

int h_pos[100][2];
int c_pos[13][2];
int h_num = 0, c_num = 0;

int dis_min = 10000000;

void changeMin(int selected) {
	int t_dis = 0;
	for (int i = 0; i < h_num; i++) {
		t_dis += lenList[selected - 1][i];
	}
	if (t_dis < dis_min)
		dis_min = t_dis;
}

void findMin(int selected, int remain_c) {
	if (selected == remain_c) {
		changeMin(selected);
	}
	int nextIndex = selected_c.empty() ? 0 : selected_c.back() + 1;
	for (int i = nextIndex; i < c_num; i++) {
		selected_c.push_back(i);
		for (int j = 0; j < h_num; j++) {
			int dis = abs(c_pos[i][0] - h_pos[j][0]) + abs(c_pos[i][1] - h_pos[j][1]);
			if (selected > 0)
				dis = dis < lenList[selected - 1][j] ? dis : lenList[selected - 1][j];
			lenList[selected][j] = dis;
		}
		findMin(selected + 1, remain_c);
		selected_c.pop_back();
	}
}

int main() {
	int length, remain_c;
	cin >> length >> remain_c;

	for(int i=0; i<length; i++) {
		for (int j = 0; j < length; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				h_pos[h_num][0] = i;
				h_pos[h_num][1] = j;
				h_num++;
			}
			else if (num == 2) {
				c_pos[c_num][0] = i;
				c_pos[c_num][1] = j;
				c_num++;
			}
		}
	}
	findMin(0, remain_c);
	cout << dis_min;
}