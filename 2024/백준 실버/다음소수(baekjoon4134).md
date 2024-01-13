수 이어가기
====
<br/>

>### 문제 유형/난이도
>실버4 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/4134">문제 바로 가기(baekjoon 4134)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long input) {
    if(input<2) return false;

    double range=sqrt(input);
    for(int i=2; i<=range+1; i++) {
        if(input%i==0 && input!=i) {
            return false;
        }
    }
    return true;
}

int main() {
    int testCase;
    cin>>testCase;

    for(; testCase>0; testCase--) {
        long long input;
        cin>>input;

        while(true) {
            if(isPrime(input)) break;

            input++;
        }

        cout<<input<<"\n";
    }
}
```
<br/>

>### 회고
>맥북 아직 어렵다...  
>시간안에 돈다고 증명하려면 수학 공식을 찾아야 할 거 같다.  
>근데 다른 방법이 생각나는게 없었다.  
