연료채우기
====
<br/>

>### 문제 유형/난이도
>골드2 / 그리디, 우선순위큐
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1826">문제 바로 가기(baekjoon 1826)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int, int>> infos(n);
    for(int i=0; i<n; i++) {
        cin>>infos[i].first>>infos[i].second;
    }
    sort(infos.begin(), infos.end());

    int target, currFuel;
    cin>>target>>currFuel;

    int infoIndex=0;
    priority_queue<int> pq;

    int cnt=0;

    while(currFuel<target) {
        while(infoIndex<infos.size() && currFuel>=infos[infoIndex].first) {
            pq.push(infos[infoIndex].second);
            infoIndex++;
        }
        
        if(pq.empty()) {
            break;
        }
        
        currFuel+=pq.top();
        pq.pop();
        cnt++;
    }

    if(currFuel<target) {
        cout<<-1;
    }
    else {
        cout<<cnt;        
    }
}
```
<br/>

>### 회고
>문제를 보자마자 우선순위 큐를 이용하면 쉽게 해결할 수 있겠다는 생각이 들었다. 그에 비해 우선순위 큐를 자주 사용해보지 않아서 그런지 구현은 조금 더 여려웠던 것 같다. 그래도 나름 쉽게 해결한 것 같아 성취감이 든다