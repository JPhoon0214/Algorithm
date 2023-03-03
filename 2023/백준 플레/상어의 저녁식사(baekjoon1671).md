상어의 저녁식사
====
<br/>

>### 문제 유형/난이도
>플레3 / 이분 매칭
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1671">문제 바로 가기(baekjoon 1671)</a>
<br/>

>### 코드
```C++
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
```
<br/>

>### 회고
>이분 매칭 개념의 난이도도 조금 있을 뿐더러 이 문제는 이분 매칭을 적용해보자는 발상을 하는것 역시 어려운 문제였다. 나는 이분 매칭 문제를 풀어보고 싶어 처음부터 이분 매칭 문제를 찾아서 푼 것이기 때문에 훨씬 쉽게 푼 감이 있다. 아마 대회나 시험 등에서 이런 문제를 마주쳤다면 이분매칭을 떠올리지 못할지도 모르겠다...