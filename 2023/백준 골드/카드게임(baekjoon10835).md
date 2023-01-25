카드게임
====
<br/>

>### 문제 유형/난이도
>골드5 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/10835">문제 바로 가기(baekjoon 10835)</a>
<br/>

>### 코드
```C++
#include <iostream>
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
}
```
<br/>

>### 회고
>처음으로 vim을 이용해 코딩을 해 보았다. 처음이라 그런지 못해먹겠다... 그래도 좀더 연습해 볼 생각이다.
>문제는 카드의 개수가 많지 않아 큰 고민 없이 현재 카드 더미 가장 위에 있는 카드 상태가 주어질 때 최대 점수를 저장하는 방식으로 구현하였다.