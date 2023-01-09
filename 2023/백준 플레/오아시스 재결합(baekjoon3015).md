오아시스 재결합
====
<br/>

>### 문제 유형/난이도
>플레5 / 스택
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/3015">문제 바로 가기(baekjoon 3015)</a>
<br/>

>### 코드
```C++
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
```
<br/>

>### 회고
>예전부터 계속 풀어보려 시도했던 문제다. 키가 같은 사람을 처리하는 방법이 까다롭다는 것이 이 문제를 어렵게 만드는 거의 유일한 요소이다. 나는 고민 끝에 키가 같은 사람이 두명 이상 있을 경우, 스택에 두 사람을 저장하는 대신, pair<int, int> 구조체를 이용해 첫번째 원소에 키를, 두번째 원소에 그 키를 가진 사람 수를 저장하도록 하였다.
>나는 입력을 받은 값을 뒤에서부터 순회하면서 함수에 집어넣었는데, 풀다가 그럴 필요가 없었다는 것을 깨달았다. 입력받은 순서대로 계산하든, 역순으로 계산하든 별 상관 없을 것으로 보인다.
>이 문제를 푸는데 가장 중요한 아이디어는 어떤 사람보다 더 키가 큰 사람이 나타나는 순간, 앞서 나온 키가 더 작은 사람은 더 이상 서로 볼 수 있는 사람이 없다는 것이다.