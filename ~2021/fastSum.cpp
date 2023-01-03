#include <iostream>

using namespace std;

int fastSum(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 1) {
		return fastSum(n - 1) + n;
	}
	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}

int main() {
	// 1 부터 100 까지 숫자의 합
	int n = 100;
	cout << fastSum(n);
}