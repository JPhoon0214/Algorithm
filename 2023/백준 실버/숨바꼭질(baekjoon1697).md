숨바꼭질
====
<br/>

>### 문제 유형/난이도
>실버1 / BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1697">문제 바로 가기(baekjoon 1697)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <queue>

using namespace std;

struct Info {
    int pos;
    int time;
};

int main() {
    int myPos, targetPos;
    cin>>myPos>>targetPos;

    queue<Info> que;
    que.push({myPos, 0});

    vector<bool> visited(100001, false);

    while(!que.empty()) {
        int currPos=que.front().pos;
        int currTime=que.front().time;
        que.pop();

        visited[currPos]=true;

        if(currPos==targetPos) {
            cout<<currTime;
            break;
        }

        if(currPos+1<=100000 && !visited[currPos+1]) {
            que.push({currPos+1, currTime+1});
        }
        if(currPos-1>=0 && !visited[currPos-1]) {
            que.push({currPos-1, currTime+1});
        }
        if(currPos*2<=100000 && !visited[currPos*2]) {
            que.push({currPos*2, currTime+1});
        }
    }
}
```
<br/>

>### 회고
>처음에 메모리 초과가 났었다. 사실 메모리 계산을 해보지 않았는데, 다시 생각해보니 각 지점 별 방문 여부만 저장해도 시간 및 공간 복잡도를 많이 줄일 수 있겠다는 생각이 들었다.
>앞으로 너비 우선 탐색 문제를 풀 때 이 방법을 많이 떠올려야겠다.