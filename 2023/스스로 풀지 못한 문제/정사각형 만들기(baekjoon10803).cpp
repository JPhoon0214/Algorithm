#include <iostream>
#include <vector>

using namespace std;

int getMin(int height, int width, vector<vector<int>> &cache) {
  int &ret = cache[height][width];
  if (ret != -1) {
    return ret;
  }
  ret = 987654321;

  if (height > width) {
    if (height % width == 0) {
      ret = height / width;
    } else {
      if (height > width * 3) {
        ret = getMin(height - width, width, cache) + 1;
      } else {
        for (int i = 1; i < height; i++) {
          ret = min(ret,
                    getMin(i, width, cache) + getMin(height - i, width, cache));
        }
        for (int i = 1; i < width; i++) {
          ret = min(ret, getMin(height, i, cache) +
                             getMin(height, width - i, cache));
        }
      }
    }
  } else {
    if (width % height == 0) {
      ret = width / height;
    } else {
      if (width > height * 3) {
        ret = getMin(height, width - height, cache) + 1;
      } else {
        for (int i = 1; i < height; i++) {
          ret = min(ret,
                    getMin(i, width, cache) + getMin(height - i, width, cache));
        }
        for (int i = 1; i < width; i++) {
          ret = min(ret, getMin(height, i, cache) +
                             getMin(height, width - i, cache));
        }
      }
    }
  }
  return ret;
}

int main() {
  int height, width;
  cin >> height >> width;

  vector<vector<int>> cache(height + 1, vector<int>(width + 1, -1));

  cout << getMin(height, width, cache);
}