#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> storeData;

long long ret = 0;

void countPairs(int height) {
  if (storeData.empty()) {
    storeData.push_back({height, 1});
  } else if (storeData.back().first < height) {
    ret += storeData.back().second;
    storeData.pop_back();
    countPairs(height);
  } else if (storeData.back().first > height) {
    ret++;
    storeData.push_back({height, 1});
  } else {
    ret += storeData.back().second;
    if (storeData.size() > 1)
      ret++;
    storeData.back().second += 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int peopleNum;
  cin >> peopleNum;
  vector<int> heights(peopleNum);
  for (int i = 0; i < peopleNum; i++) {
    cin >> heights[i];
  }
  for (int i = peopleNum - 1; i >= 0; i--) {
    countPairs(heights[i]);
  }
  cout << ret;
}