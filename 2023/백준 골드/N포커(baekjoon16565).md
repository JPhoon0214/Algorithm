N포커
====
<br/>

>### 문제 유형/난이도
>골드2 / DP, 조합론
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/16565">문제 바로 가기(baekjoon 16565)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(53, vector<int>(53, -1));

int combination(int total, int pick) {
    if(total==pick || pick==0) {
        return 1;
    }
    int& ret=cache[total][pick];
    if(ret!=-1) {
        return ret;
    }

    return ret=(combination(total-1, pick-1)+combination(total-1, pick))%10007;    
}

int main() {
    int cardNum;
    cin>>cardNum;

    int ret=0;
    for(int i=4; cardNum-i>=0; i+=4) {
        int currPick=i/4;
        if(currPick%2==1) {
            ret+=(combination(13, currPick)*combination(52-i, cardNum-i))%10007;
            ret%=10007;
        }
        else {
            ret-=(combination(13, currPick)*combination(52-i, cardNum-i))%10007;
            if(ret<0) {
                ret+=10007;
            }
        }
    }
    
    cout<<ret;
}
```
<br/>

>### 회고
>약간 고등학교 확통 문제 같았다. n combination r = n-1 combination r + n-1 combination r-1 이라는 것을 안다면 이를 DP로 저장해 풀 수 있음을 알 수 있다.