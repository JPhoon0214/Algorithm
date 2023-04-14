망가진 계산기
====
<br/>

>### 문제 유형/난이도
>골드1 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1443">문제 바로 가기(baekjoon 1443)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int availShow, calNum;

int calReturn(vector<int>& countPerNum) {
    int ret=1;
    for(int i=2; i<10; i++) {
        for(int j=0; j<countPerNum[i]; j++) {
            ret*=i;
            string retToString=to_string(ret);
            if(retToString.size()>availShow) {
                return -1;
            }
        }
    }
    
    return ret;
}

int getMax(int currNum, vector<int>& countPerNum, int remain) {
    if(currNum==10) {        
        return calReturn(countPerNum);
    }
    else if(currNum==9) {
        countPerNum[currNum]=remain;
        int ret=getMax(currNum+1, countPerNum, 0);
        countPerNum[currNum]=0;
        return ret;
    }
    
    int ret=-1;    
    
    for(int i=remain; i>=0; i--) {
        countPerNum[currNum]=i;
        int currMax=getMax(currNum+1, countPerNum, remain-i);
        countPerNum[currNum]=0;
        
        if(currMax==-1) {
            break;
        }        
        ret=max(ret, currMax);
    }
    return ret;
}

int main() {
    cin>>availShow>>calNum;
    vector<int> countPerNum(10, 0);
    cout<<getMax(2, countPerNum, calNum);
}
```
<br/>

>### 회고
>문제를 풀었는데 레이팅이 내려갔다...왜지...지금까지 푼 문제 중 난이도가 변한 문제가 있는 모양이다. 아이디어 자체는 어렵지 않았자민, 최적화가 필요했다.