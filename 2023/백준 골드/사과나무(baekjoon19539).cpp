#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> heights(n);

  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  int sumAll = 0;
  for (int i = 0; i < n; i++) {
    sumAll += heights[i];
  }

  if (sumAll % 3 == 0) {
    int usedTimes = sumAll / 3;

    int oddCount = 0;
    for (int i = 0; i < n; i++) {
      if (heights[i] % 2 == 1) {
        oddCount++;
      }
    }

    if (oddCount > usedTimes) {
      cout << "NO";
    } else {
      int remain = usedTimes - oddCount;
      if (remain % 2 == 0) {
        cout << "YES";
      } else {
        cout << "NO";
      }
    }
  } else {
    cout << "NO";
  }
}