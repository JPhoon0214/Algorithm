#include <iostream>

using namespace std;

int nums[1000001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, e;
	cin >> s >> e;

	nums[1]++;
	for (int i = 2; i <= e/2; i++) {
		if (nums[i])
			continue;
		for (int j = 2; i * j < 1000001; j++)
			nums[i * j]++;
	}

	int count = 0;
	for (int i = s; i <= e; i++) {
		if (!nums[i])
			cout << i << "\n";
	}
}
