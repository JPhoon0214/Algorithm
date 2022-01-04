#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> list;
vector<char> vowel = { 'a', 'e','i', 'o', 'u' };
int toChoice;

bool checkValidation(vector<int>& numList) {
	int vowelNum = 0;
	vector<int>::iterator iter;

	for (iter = numList.begin(); iter != numList.end(); iter++) {
		if (find(vowel.begin(), vowel.end(), list[*iter]) != vowel.end())
			vowelNum++;
	}
	if(vowelNum >=1 && vowelNum <= toChoice - 2)
		return true;
	return false;

}

void printWord(vector<int>& numList) {
	vector<int>::iterator iter;
	if (checkValidation(numList)) {
		for (iter = numList.begin(); iter != numList.end(); iter++) {
			cout << list[*iter];
		}
		cout << endl;
	}
}

void findWord(int remain, int totalWordNum, vector<int>& numList) {
	if (remain == 0)
		printWord(numList);

	int	smallest = numList.empty() ? 0 : numList.back() + 1;
	for (int i = smallest; i < totalWordNum; i++) {
		numList.push_back(i);
		findWord(remain - 1, totalWordNum, numList);
		numList.pop_back();
	}
}

int main() {
	int wordNum;
	vector<int> numList;

	cin >> toChoice >> wordNum;
	for (int i = 0; i < wordNum; i++) {
		char word;
		cin >> word;
		list.push_back(word);
	}
	sort(list.begin(), list.end());
	findWord(toChoice, wordNum, numList);
	
}