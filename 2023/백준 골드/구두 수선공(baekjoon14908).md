구두 수선공
====
<br/>

>### 문제 유형/난이도
>골드1 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14908">문제 바로 가기(baekjoon 14908)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int time;
    int cost;
    int index;
    bool operator<(Info& next);
};
bool Info::operator<(Info& next) {
    if(cost*next.time<next.cost*time) {
        return true;        
    }
    else if(cost*next.time>next.cost*time) {
        return false;        
    }
    else {
        return index>next.index;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int taskNum;
    cin>>taskNum;
    vector<Info> infos(taskNum);
    for(int i=0; i<taskNum; i++) {
        cin>>infos[i].time>>infos[i].cost;
        infos[i].index=i+1;
    }
    sort(infos.begin(), infos.end());
    for(int i=taskNum-1; i>=0; i--) {
        cout<<infos[i].index<<" ";
    }
}
```
<br/>

>### 회고
>>두 작업 시간을 T1, T2 두 작업을 하지 않았을 때 하루 당 보상금을 S1, S2라고 했을 때, 첫번째 작업을 먼저 할 경우 보상금은 T1 * S2 이고, 두번째 작업을 먼저할 경우는 T2 * S1이다. 또한 만일 T1 * S2(S1를 먼저 할 경우) > T2 * S1(S2를 먼저 할 경우) && T2 * S3(S2를 먼저할 경우) > T3 * S2(S3를 먼저 할 경우) 일 경우 T1 * S3(S1을 먼저 할 경우) > T3 * S1(S3를 먼저 할 경우)는 자동으로 성립한다. 이에 따라 대소 비교 함수를 작성하였다. 이때 값이 같다면 오름차순으로 가장 먼저 출력되는 순서를 찾기 위해 인덱스 비교도 하였다.