수 이어가기
====
<br/>

>### 문제 유형/난이도
>실버5 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2635">문제 바로 가기(baekjoon 2635)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input;
    cin>>input;

    int maxCnt=-1;
    int maxAft=-1;
    for(int i=1; i<=input; i++) {
        int currCnt=2;
        int bef=input, aft=i;
        while(true) {
            int temp=aft;
            aft=bef-aft;
            bef=temp;

            if(aft<0) break;

            currCnt++;
        }
        if(maxCnt<currCnt) {
            maxCnt=currCnt;
            maxAft=i;
        }
    }

    cout<<maxCnt<<"\n";

    int bef=input, aft=maxAft;
    cout<<bef<<" "<<aft<<" ";
    while(true) {
        int temp=aft;
        aft=bef-aft;
        bef=temp;

        if(aft<0) break;

        cout<<aft<<" ";
    }
}
```
<br/>

>### 회고
>오늘 졸업한 동생이랑 놀다 컵도 깨먹고 선배님하고 놀다 보니 새벽 늦은 시간이 되어 버렸다.  
>좀 더 어려운 문제를 풀려 했는데 언능 자고 싶어서 쉬운 문제로 풀었다.
>그렇게 멋진 코드는 아닌거 같다. 1번째 수와 2번째 수를 따로 예외 처리해서 출력하는 부분도 그렇고, 정답이 되는 순열에 대해서는 두번 탐색 하는 부분도 그렇다.  
>변수들도 조금 가독성이 떨어지는 것 같다.  
>잘 못 짰지만 오늘은 언능 자고 내일은 좀더 맨정신으로 문제를 풀어보겠다.
