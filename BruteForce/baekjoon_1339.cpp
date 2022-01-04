#include <iostream>
#include <vector>

using namespace std;

vector<string> words;
int alphabet[26] = { 0 };

vector<int> usedAlpha;
int usedAlphaNum = 0;

vector<int> values;
vector<int> mapped;

int max_num = 0;

void changeMax() {
	int alphaValues[26] = { 0 };
	for (int i = 0; i < usedAlphaNum; i++) {
		alphaValues[usedAlpha[i]] = mapped[i];
	}
	int totalNum = 0;

	for (int i = 0; i < words.size(); i++) {
		int digit = 1;
		for (int j = words[i].length() - 1; j >= 0; j--) {
			char letter = words[i][j];
			totalNum += alphaValues[letter - 'A'] * digit;
			digit *= 10;
		}
	}
	if (max_num < totalNum)
		max_num = totalNum;
}

void cal() {
	if (values.empty())
		changeMax();
	for (int i = values.size() - 1; i >= 0; i--) {
		int data = values[i];
		mapped.push_back(data);
		values.erase(values.begin() + i);
		cal();
		values.insert(values.begin() + i, data);
		mapped.pop_back();
	}
}

int main() {
	int wordNum;
	cin >> wordNum;
	for (int i = 0; i < wordNum; i++) {
		string word;
		cin >> word;
		words.push_back(word);
		for (int j = 0; j < word.length(); j++) {
			alphabet[word[j] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] != 0) {
			usedAlpha.push_back(i);
			usedAlphaNum++;
		}
	}
	for (int i = 10 - usedAlphaNum; i < 10; i++)
		values.push_back(i);
	cal();
	cout << max_num;
}
