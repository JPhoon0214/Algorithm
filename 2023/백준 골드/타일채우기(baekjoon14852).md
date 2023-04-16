타일채우기
====
<br/>

>### 문제 유형/난이도
>골드4/ DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14852">문제 바로 가기(baekjoon 14852)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <cstring>

using namespace std;

int cache[1000001];

/*
int calCaseNum(int width) {
    if(width<=0) {
        return 1;
    }
    else if(width==1) {
        return 2;
    }
    else if(width==2) {
        return 7;
    }
    
    int& ret=cache[width];
    if(ret!=-1) {
        return ret;
    }

    //ret=((long long)calCaseNum(width-1)*3+(long long)calCaseNum(width-2)-(long long)calCaseNum(width-3))%1000000007;
    ret=((long long)calCaseNum(width-10)*3)%1000000007;
    
    return ret;
}
*/

int main() {
    int width;
    cin>>width;

    memset(cache, -1, sizeof(cache));

    for(int i=0; i<=width; i++) {
        if(i==0) cache[i]=1;
        else if(i==1) cache[i]=2;
        else if(i==2) cache[i]=7;
        else {
            cache[i]=((long long)cache[i-1]*3+cache[i-2]-cache[i-3])%1000000007;
            cache[i]=cache[i]>=0 ? cache[i] : cache[i]+1000000007;
        }        
    }

    cout<<cache[width];
}
```
<br/>

>### 회고
> 처음 풀었을때 콜 스택 초과가 났다.
> 재귀함수를 사용할 땐 조심해야겠다.  
> 관련 내용은 github.io페이지에 정리해놨다.