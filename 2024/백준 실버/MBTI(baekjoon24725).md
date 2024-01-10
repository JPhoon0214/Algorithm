수 이어가기
====
<br/>

>### 문제 유형/난이도
>실버3 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/4375">문제 바로 가기(baekjoon 4375)</a>

<br/>

>### 코드
```C++
#include <iostream>

using namespace std;

int main() {
    while(true) {
        int input;
        cin>>input;

        if(cin.eof()) break;

        int cnt=0;
        int currRemain=0;
        while(true) {
            cnt++;
            currRemain*=10;
            currRemain+=1;
            currRemain%=input;
            if(currRemain==0) break;
        }
        cout<<cnt<<"\n";
    }
}
```
<br/>

>### 회고
>실전에서 이 문제를 브루트포스로 풀 엄두를 낼 수 있었을까?? 확신은 안 섰을 것 같다.  
>그래도 여러 정황상 결국 브루트포스로 풀지 않았을까  
>그냥 숫자를 만들어서 나머지를 구하면 오버플로가 날 수도 있다 생가해서 이전 자리수의 나머지를 구한 후 10을 곱해 다시 나머지를 구하는 방식으로 진행했다.  
>long long을 이용해도 잘해야 19자리 정도밖에 계산 못하지만, 위와 같이 하면 1억 자리도 계산할 수 있다.  
