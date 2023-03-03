#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Info {
  int values[3];
  int index;
};

int sharkNum;

bool checkCanEat(Info &infoMe, Info &infoOther) {
  bool allGreater = true;
  for (int i = 0; i < 3; i++) {
    if (infoMe.values[i] < infoOther.values[i]) {
      allGreater = false;
      break;
    }
  }

  bool allSame = true;
  for (int i = 0; i < 3; i++) {
    if (infoMe.values[i] != infoOther.values[i]) {
      allSame = false;
      break;
    }
  }

  if (allSame) {
    return infoMe.index < infoOther.index;
  } else {
    return allGreater;
  }
}

bool dfs(vector<vector<int>> &availToEat, vector<int> &matching,
         vector<bool> &visited, int sharkIndex) {
  for (int i = 0; i < availToEat[sharkIndex].size(); i++) {
    int currOtherIndex = availToEat[sharkIndex][i];

    if (visited[currOtherIndex]) {
      continue;
    }

    visited[currOtherIndex] = true;

    if (matching[currOtherIndex] == -1 ||
        dfs(availToEat, matching, visited, matching[currOtherIndex])) {
      matching[currOtherIndex] = sharkIndex;
      return true;
    }
  }
  return false;
}

int main() {
  cin >> sharkNum;

  vector<Info> infos(sharkNum);

  for (int i = 0; i < sharkNum; i++) {
    Info currInfo;
    cin >> currInfo.values[0] >> currInfo.values[1] >> currInfo.values[2];
    currInfo.index = i;
    infos[i] = currInfo;
  }

  int cnt = 0;

  vector<vector<int>> availToEat(sharkNum, vector<int>());

  for (int i = 0; i < sharkNum; i++) {
    for (int j = 0; j < sharkNum; j++) {
      if (i == j) {
        continue;
      }
      if (checkCanEat(infos[i], infos[j])) {
        availToEat[i].push_back(j);
      }
    }
  }

  vector<int> matching(sharkNum, -1);

  for (int i = 0; i < sharkNum; i++) {
    vector<bool> visited(sharkNum, false);
    if (dfs(availToEat, matching, visited, i)) {
      cnt++;
    }
  }

  for (int i = 0; i < sharkNum; i++) {
    vector<bool> visited(sharkNum, false);
    if (dfs(availToEat, matching, visited, i)) {
      cnt++;
    }
  }

  cout << sharkNum - cnt;
}