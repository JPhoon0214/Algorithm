행복 유치원
====
<br/>

>### 문제 유형/난이도
>골드5 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/13164">문제 바로 가기(baekjoon 13164)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int childNum, groupNum;
    cin>>childNum>>groupNum;
    vector<int> heights(childNum);
    for(int i=0; i<childNum; i++) {
        cin>>heights[i];
    }
    sort(heights.begin(), heights.end());

    vector<int> gaps(childNum-1);
    for(int i=1; i<childNum; i++) {
        gaps[i-1]=heights[i]-heights[i-1];
    }

    sort(gaps.begin(), gaps.end());

    int ret=0;
    for(int i=0; i<gaps.size()-groupNum+1; i++) {
        ret+=gaps[i];
    }
    cout<<ret;
}
```
<br/>

>### 회고
>최근 문제를 많이 안 풀어서 solved.ac 잔디밭이 옅은 색이었는데, 오늘 이미 2문제를 풀어 한 문제만 더 풀면 조금 더 진한 색 잔디밭이 되기 때문에 빠르게 한 문제를 더 풀어 보았다. 학생들을 키 순으로 배열한 후, 인접한 학생들의 키 차이를 배열에 저장한다. 그룹의 수가 n개라면, 이렇게 그룹 지음으로써 무시할 수 있는 키 차이의 개수는 n-1개 이므로, 가장 큰 키 차이 n-1개를 제외한 나머지 키 차이들의 합을 구하였다.