시로코와 은행털기
====
<br/>

>### 문제 유형/난이도
>골드4 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/26607">문제 바로 가기(baekjoon 26607)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[80][81][16001];

int isAvail(vector<int>& strengths, int index, int toPick, int target) {
    if(index+1<toPick || target<0) {
        return 0;        
    }
    if(toPick==0) {
        return target==0;
    }
    if(index==0) {
        return target==strengths[index];
    }
    
    if(cache[index][toPick][target]!=-1) 
        return cache[index][toPick][target];
    
    int ret=max(isAvail(strengths, index-1, toPick, target), isAvail(strengths, index-1, toPick-1, target-strengths[index]));
    return cache[index][toPick][target]=ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, x;
    cin>>n>>k>>x;
    vector<int> strengths(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>strengths[i]>>temp;
    }
    memset(cache, -1, sizeof(cache));
    
    int ret=0;
    for(int i=0; i<=x*k; i++) {
        if(isAvail(strengths, n-1, k, i)) {
            ret=max(ret, i*(k*x-i));
        }
    }
    cout<<ret;
}
```
<br/>

>### 회고
>나는 코더다 송년 대회 첫번째 문제였다.
>우선 대회 총평을 해보자면...상당히 어려운 문제 위주로 출제되었다.
>아직 나에게는 버거웠지만, 올 한해 동안 열심히 공부하면 어느정도 풀 수 있을 것 같다.<br/>

>이 문제는 DP를 이용하여 풀었다. DP를 어떻게 이용할지 아이디어를 떠올리면 이후 구현이 복잡하지는 않다.
>그럼에도 나는 이 문제를 대회 시간 안에 풀지 못했는데,
> >1. 우선 DP를 이용해야겠다는 생각을 하지 못했다. 자료의 개수가 비교적 적은 80개 남짓이었기 때문에, 적당히 조작을 한다면 브루트포스로 충분히 풀 수 있을 것이라 생각했다. 사실 그럼에도 브루트포스를 이용하기엔 너무 큰 숫자였지만 이 방을 고수하다가 다른 방법을 생각해내지 못했다.
> >2. DP를 사용하기엔 메모리가 부족하다고 생각했다. 실제로 위 방식으로 구현할 경우 cache를 구현하기 위한 메모리가 상당히 크다. 뿐만 아니라 DP에서 중복으로 처리할 문제의 기준을 정하는 아이디어를 떠올리지 못했던 것이 큰 원인이었다.<br/>
    
>또 다른 문제를 마주쳤을 때 DP를 떠올릴 수 있을지는 잘 모르겠다.
>지금의 나로서는 쉽지 않을 것 같기도 하지만, 그래도 이번 대회처럼 풀 수 있는 문제를 틀리지 말아야 겠다.