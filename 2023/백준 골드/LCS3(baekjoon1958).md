LCS3
====
<br/>

>### 문제 유형/난이도
>골드3 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1958">문제 바로 가기(baekjoon 1958)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101][101];
string input1, input2, input3;

bool allSame(char let1, char let2, char let3) {
    return ((let1==let2) && (let2==let3));
}

int getLCS(int ptr1, int ptr2, int ptr3) {
    if(ptr1==input1.size() || ptr2==input2.size() || ptr3==input3.size())
        return 0;

    int& ret=cache[ptr1][ptr2][ptr3];
    if(cache[ptr1][ptr2][ptr3]!=-1)
        return ret;
    char let1=input1[ptr1], let2=input2[ptr2], let3=input3[ptr3];
    ret=allSame(let1, let2, let3) ? 1+getLCS(ptr1+1, ptr2+1, ptr3+1) : 0;

    ret=max(ret, getLCS(ptr1+1, ptr2, ptr3));
    ret=max(ret, getLCS(ptr1, ptr2+1, ptr3));
    ret=max(ret, getLCS(ptr1, ptr2, ptr3+1));
    return ret;
}

int main() {
    cin>>input1>>input2>>input3;
    memset(cache, -1, sizeof(cache));
    cout<<getLCS(0, 0, 0);
}
```
<br/>

>### 회고
>오랜만에 쓰는 알고리즘 회고다. 오랜만에 쓰는 이유는 바로바로...어제까지 휴가를 다녀왔기 때문이다. 그래도 백준 스트릭 깨지는건 싫어서 휴가 동안도 하루에 한 문제씩은 풀긴 풀었다
>오늘 푼 문제는 변형된 LCS로 기본 LCS개념을 잘 알고 있으면 쉽게 풀 수도 있는 문제였다. 하지만 나는 예전에 LCS개념을 처음 접했을 때 어렵다고 생각한 이후로, LCS 공부를 계속 미루고 있었어서 개념을 잘 알지는 못했다. 그 마저도 반복문을 이용한 DP를 활용해 푸는 방법을 공부했었는데, 위 문제는 문자열이 하나가 늘어날 때 마다 반복문이 한겹이 늘어나 생각하기 매우 까다로울 것이다. 이 때문에 재귀를 이용해 해결하였다.
>
>처음에 겁먹었던 것과는 달리 큰 어려움 없이 풀 수 있었다. 매개변수와 문자열을 배열로 저장해 반복문을 이용해 함수를 조금 더 짧게 작성할 수도 있으며, 위 문제는 단순히 재귀 호출문을 3번 써도 코드의 가독성에 큰 해가 없을 것이라 여겨 반복문을 이용하지는 않았다. 예전에 알고리즘을 처음 했을때는 어렵다고 생각했던 LCS였는데, 조금 더 어렵게 변형된 LCS를 관련 개념을 거의 까먹은 상태에서도 쉽게 풀어내어 실력이 좀 늘은 것 같다는 생각이 들었다. 앞으로 더 열심히 정진해서 지금 어렵게 느껴지는 문제들도 쉽게 풀 수 있는 날이 오도록 해야겠다.