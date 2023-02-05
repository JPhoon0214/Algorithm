전시장
====
<br/>

>### 문제 유형/난이도
>골드2 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2515">문제 바로 가기(baekjoon 2515)</a>
<br/>

>### 코드
```C++
[#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(2000, vector<int>(2000, -1));

int n;

int getMax(vector<int>& left, vector<int>& right, int leftIndex, int rightIndex) {
    if(leftIndex==n || rightIndex==n) {
        return 0;
    }
    int& ret=cache[leftIndex][rightIndex];
    if(cache[leftIndex][rightIndex]!=-1) {
        return ret;
    }
    ret=max(ret, getMax(left, right, leftIndex+1, rightIndex));
    ret=max(ret, getMax(left, right, leftIndex+1, rightIndex+1));
    if(left[leftIndex]>right[rightIndex]) {
        ret=max(ret, getMax(left, right, leftIndex, rightIndex+1)+right[rightIndex]);
    }
    return ret;
}

int main() {
    cin>>n;
    vector<int> left(n);
    vector<int> right(n);
    for(int i=0; i<n; i++) {
        cin>>left[i];
    }
    for(int i=0; i<n; i++) {
        cin>>right[i];
    }
    cout<<getMax(left, right, 0, 0); 
}](#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int paintNum, availHeight;
vector<pair<int, int>> inputs; //height, value

vector<int> cache(300000, -1);

int getLowerBound(int target, int start) {
    start--;
    int end=inputs.size();
    if(inputs.back().first>=target) {
        while(start+1<end) {
            int mid=(start+end)/2;
            if(inputs[mid].first<target) {
                start=mid;
            }
            else {
                end=mid;
            }
        }        
    }
    return end;
}

int getMax(int index) {
    if(index>=paintNum) {
        return 0;
    }

    int& ret=cache[index];
    if(ret!=-1) {
        return ret;
    }

    int nextIndex=getLowerBound(inputs[index].first+availHeight, index+1);
    ret=max(ret, getMax(index+1));
    ret=max(ret, getMax(nextIndex)+inputs[index].second);
    return ret;
}

int main() {
    cin>>paintNum>>availHeight;
    for(int i=0; i<paintNum; i++) {
        int height, value;
        cin>>height>>value;
        inputs.push_back({height, value});
    }
    sort(inputs.begin(), inputs.end());
    cout<<getMax(0);
})
```
<br/>

>### 회고
>lower_bound 함수를 사용해 보려 했지만, 구조체에서 원하는 대로 사용하는 방법을 알지 못해서 직접 이분탐색을 구현할 수 밖에 없었다. 라이브러리 공부를 조금 더 해야겠다.