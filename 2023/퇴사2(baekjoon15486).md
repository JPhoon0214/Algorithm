퇴사2
====
<br/>

>### 문제 유형/난이도
>골드5 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/15486">문제 바로 가기(baekjoon 15486)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> cache(n+1, 0);
    vector<pair<int, int>> inputs(n);
    for(int i=0; i<n; i++) {
        cin>>inputs[i].first>>inputs[i].second;
    }

    int befHighestCost=-1;
    for(int i=0; i<n; i++) {
        befHighestCost=max(befHighestCost, cache[i]);
        int period=inputs[i].first;
        int day=i+1;
        if(day+period-1>n)
            continue;
        cache[day+period-1]=max(cache[day+period-1], befHighestCost+inputs[i].second);
    }

    int ret=0;
    for(int i=0; i<n+1; i++) {
        ret=max(ret, cache[i]);
    }
    cout<<ret;
}
```
<br/>

>### 회고
>DP를 이용한 간단한 문제였다. 대회에서 DP문제를 맞추지 못해 풀어 봤다.
>자료의 개수가 1,500,000개이기 때문에 브루트포스로는 풀 수 없다는 것은 쉽게 알 수 있다.
>이때 브루트포스 알고리즘에서 중복되는 부분을 찾아보면, k번째 날에 한 작업과 m번째 날에 한 작업이 똑같이 n일에 끝이 났다면, n일 이후의 계산은 k째 날에 작업을 할 경우 얻을 수 있는 총 보상과 m번째 날에 작업을 할 경우 얻을 수 있는 총 보상 중 더 큰 값 하나만 계산해도 무방하다는 것을 알 수 있다.
>이 때문에 cache[i]는 i일에 끝나는 작업을 할 경우 벌 수 있는 최대값을 저장하도록 했다.<br/>
>조금 특이한 점은 cache[i]값이 한번에 결정되는 것이 아니라 i-1번째 날까지 진행하면서 계속 변경된다는 점이다.
>cache[i]의 값을 한번에 결정하기 위해선 i번째 날에 끝나는 작업을 일일히 찾아줘야 하는데, 이 방법으로 할 경우 시간 제한한에 걸릴 것이다.
>cache[i] 값은 i번 인덱스 이전 값을 계산할 때는 전혀 쓰이지 않고, i번 인덱스 이후 값을 사용하기 전에 완전히 확정되기 때문에 i-1번째 인덱스까지 진행하면서 지속적으로 수정해주는 방법으로 DP를 사용해도 문제 없다.