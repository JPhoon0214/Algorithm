호텔
====
<br/>

>### 문제 유형/난이도
>골드5 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1106">문제 바로 가기(baekjoon 1106)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<int> cost;
vector<int> value;

vector<int> cache(2000, -1);

int getMinCost(int target) {
    if(target<=0) {
        return 0;
    }
    int& ret=cache[target];
    if(ret!=-1) {
        return ret;
    }

    ret=987654321;
    for(int i=0; i<cost.size(); i++) {
        ret=min(ret, cost[i]+getMinCost(target-value[i]));
    }
    return ret;
}

int main() {
    int target, cityNum;
    cin>>target>>cityNum;
    for(int i=0; i<cityNum; i++) {
        int cityCost, cityValue;
        cin>>cityCost>>cityValue;
        cost.push_back(cityCost);
        value.push_back(cityValue);
    }
    cout<<getMinCost(target);
}
```
<br/>

>### 회고
>원래 오늘은 조금 어려운 문제를 풀 생각이었는데, 시간이 부족해 급한대로 조금 쉬운 문제를 풀게 됐다
>그래도 반복문을 이용해 배낭 문제를 많이 구현했었는데, 이번 문제는 문제에 '최소' 라는 조건이 걸려 있어 재귀를 이용하는게 조금 더 생각하기 쉬워 보이기도 했고, 재귀를 이용한 DP를 연습 중이어서 재귀를 이용해 해결했다. 재귀를 이용해 배낭 문제를 풀어보는 기회가 되었다.