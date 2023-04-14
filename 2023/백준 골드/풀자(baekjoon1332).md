풀자
====
<br/>

>### 문제 유형/난이도
>골드3 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1332">문제 바로 가기(baekjoon 1332)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;


int calMinSolved(int startPoint, int endPoint) {
    int ret=(startPoint+3)/2;
    ret+=(endPoint-startPoint+1)/2;
    return ret;
}

int main() {
    int pNum, target;
    cin>>pNum>>target;

    vector<int> values(pNum);

    for(int i=0; i<pNum; i++) {
        cin>>values[i];
    }

    int minSolved=pNum;
    for(int i=0; i<pNum; i++) {
        for(int j=i+1; j<pNum; j++) {
            if(abs(values[i]-values[j])>=target) {
                minSolved=min(minSolved, calMinSolved(i, j));
            }
        }
    }
    cout<<minSolved;
}
```
<br/>

>### 회고
>알고리즘 블로그 포스팅을 하고 싶어서 풀었다.
>나름대로 푸는 쾌감이 있었다. 코드만 보면 쉽게 푼 것 같지만, 사실 생각을 많이 한 문제다
>calMinsolved()함수는 우아하진 않지만, 원래 이런 함수도 있는 거라 생각한다.