고층빌딩
====
<br/>

>### 문제 유형/난이도
>플레5 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1328">문제 바로 가기(baekjoon 1328)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <cstring>

using namespace std;

int calCase(int buildingNum, int leftSeen, int rightSeen, int cache[101][101][101]) {
    if(leftSeen==1 && rightSeen==1) {
        if(buildingNum==1) {
            return 1;
        }
        else {
            return 0;
        }        
    }
    if(buildingNum==0 || buildingNum+1<leftSeen+rightSeen) {
        return 0;
    }
    if(leftSeen<1 || rightSeen<1) {
        return 0;
    }

    int& ret=cache[buildingNum][leftSeen][rightSeen];
    if(ret!=-1) return ret;

    ret=0;


    ret=(ret+(long long)calCase(buildingNum-1, leftSeen-1, rightSeen, cache))%1000000007;
    ret=(ret+(long long)calCase(buildingNum-1, leftSeen, rightSeen-1, cache))%1000000007;
    ret=(ret+(long long)calCase(buildingNum-1, leftSeen, rightSeen, cache)*(buildingNum-2))%1000000007;

    return ret;
}

int main() {
    int buildingNum, leftSeen, rightSeen;
    cin>>buildingNum>>leftSeen>>rightSeen;

    int cache[101][101][101];
    memset(cache, -1, sizeof(cache));

    cout<<calCase(buildingNum, leftSeen, rightSeen, cache);
}
```
<br/>

>### 회고
>처음엔 조금 막막했지만, 빌딩을 높이 순서대로 어디에 배치하면 왼쪽과 오른쪽에서 보이는 빌딩 수가 어떻게 고민할지 손으로 대입해보면서 고민해보니 해결 방법이 보였다.
>cache[빌딩 수][왼쪽에서 보이는 빌딩 수][오른쪽에서 보이는 빌딩 수]=sum(cache[빌딩 수-1][왼쪽에서 보이는 빌딩 수-1][오른쪽에서 보이는 빌딩 수] + cache[빌딩 수-1][왼쪽에서 보이는 빌딩 수][오른쪽에서 보이는 빌딩 수-1] + cache[빌딩 수-1][왼쪽에서 보이는 빌딩 수][오른쪽에서 보이는 빌딩 수]*(빌딩 수-2)) 로 구할 수 있다.  
>기저 사례는 함수 위에 표시한 바와 같다.
>역시 그래도 DP가 가장 자신 있는 것 같다. 조금 시간을 두고 천천히 생각해보면 풀이 방법을 찾을 수 있는 것 같다.
>사실 이런 방식의 영감을 얻어 해결하는 방식 대신에 조금씩 답에 근접해가는 방식으로 문제를 풀고 싶다.
>지금은 약간 특히 어려운 문제일수록 반짝이는 영감에 의존한 문제 풀이를 하는 느낌이다.