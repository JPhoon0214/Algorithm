#include <iostream>
#include <vector>

using namespace std;

int calMinSolved(int startPoint, int endPoint) {
  int ret = (startPoint + 3) / 2;
  ret += (endPoint - startPoint + 1) / 2;
  return ret;
}

int main() {
  int pNum, target;
  cin >> pNum >> target;

  vector<int> values(pNum);

  for (int i = 0; i < pNum; i++) {
    cin >> values[i];
  }

  int minSolved = pNum;
  for (int i = 0; i < pNum; i++) {
    for (int j = i + 1; j < pNum; j++) {
      if (abs(values[i] - values[j]) >= target) {
        minSolved = min(minSolved, calMinSolved(i, j));
      }
    }
  }
  cout << minSolved;
}