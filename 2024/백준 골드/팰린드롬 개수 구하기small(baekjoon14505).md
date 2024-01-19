팰린드롬 개수 구하기
====

>### 문제 유형/난이도
>골드3 /DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14505">문제 바로 가기(baekjoon 14505)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > cache(30, vector<int>(30, -1));

int getCaseNum(int leftMid, int rightMid, string& str) {
    if(str[leftMid]!=str[rightMid]) return cache[leftMid][rightMid]=0;
    if(cache[leftMid][rightMid]!=-1) return cache[leftMid][rightMid];

    int ret=1;
    for(int left=leftMid-1; left>=0; left--) {
        for(int right=rightMid+1; right<str.size(); right++) {
            ret+=getCaseNum(left, right, str);
        }
    }
    return cache[leftMid][rightMid]=ret;
}

int main() {
    int ret=0;
    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++) {
        for(int j=i; j<str.size(); j++) {
            ret+=getCaseNum(i, j, str);
        }
    }

    cout<<ret;
}
```
<br/>

>### 회고
>부분 수열이 원 수열에서 연속된 숫자들의 집합인 줄 알고 large 버전을 풀었다 오답이 나서 일단 small 버전을 풀러 왔다.  
>일단 small 버전은 무난하게 풀렸는데, large 버전에 다시 도전해 봐야 겠다.  