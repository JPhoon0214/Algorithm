#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int index;
vector<int> lastNum = { 10 };
vector<long long> allNums;

void putNums() {
	long long nums = 0;
	long long digit = 1;
	for (int i = lastNum.size() - 1; i > 0; i--) {
		nums += lastNum[i] * digit;
		digit *= 10;
	}
	allNums.push_back(nums);
}

void count() {
	int last = lastNum.back();
	for (int i = 0; i < last; i++) {
		lastNum.push_back(i);
		putNums();
		count();
		lastNum.pop_back();
	}
}


int main() {
	cin >> index;
	count();
	sort(allNums.begin(), allNums.end());
	if (allNums.size() - 1 < index)
		cout << -1;
	else
		cout << allNums[index];
}