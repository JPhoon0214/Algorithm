#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int target;
	cin >> target;
	int i;

	for (i = 1; count != target; i++) {
		int temp = i;
		int count_6 = 0;
		while (temp) {
			if (temp % 10 == 6)
				count_6++;
			else
				count_6 = 0;
			temp /= 10;
			if (count_6 >= 3) {
				count++;
				break;
			}
		}
	}
	cout << i - 1;
}