사과나무
====
<br/>

>### 문제 유형/난이도
>골드5 / 그리디, 수학
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/19539">문제 바로 가기(baekjoon 19539)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> heights(n);

    for(int i=0; i<n; i++) {
        cin>>heights[i];
    }

    int sumAll=0;
    for(int i=0; i<n; i++) {
        sumAll+=heights[i];
    }

    if(sumAll%3==0) {
        int usedTimes=sumAll/3;

        int oddCount=0;
        for(int i=0; i<n; i++) {
            if(heights[i]%2==1) {
                oddCount++;
            }
        }

        if(oddCount>usedTimes) {
            cout<<"NO";
        }
        else {
            int remain=usedTimes-oddCount;
            if(remain%2==0) {
                cout<<"YES";
            }
            else {
                cout<<"NO";
            }
        }
    }        
    else {
        cout<<"NO";
    }
}
```
<br/>

>### 회고
>원래 그리디 알고리즘 문제를 풀고 싶었는데, 막상 문제를 보니 그리디 알고리즘이나 수학 원리를 적용할 부분을 찾지 못했다. 하지만 조건을 잘 나누어 풀면 쉽게 풀 수 있을 것 같아 조건을 잘 나누어 풀어 보았다.