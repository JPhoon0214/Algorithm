숨바꼭질4
====
<br/>

>### 문제 유형/난이도
>골드4 / BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/13913">문제 바로 가기(baekjoon 13913)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printRoad(vector<int>& cache, int index, int time) {
    if(time<0)
        return;
    
    int nextIndex=-1;
    for(int i=0; i<3; i++) {
        if(i==0) {
            if(index%2==1)
                continue;
            if(cache[index/2]==time-1) {
                nextIndex=index/2;
                break;
            }
        }
        else if(i==1) {
            if(cache[index+1]==time-1) {
                nextIndex=index+1;
                break;
            }
        }
        else {
            if(index-1>=0 && cache[index-1]==time-1) {
                nextIndex=index-1;
                break;
            }
        }
    }
    printRoad(cache, nextIndex, time-1);
    cout<<index<<" ";
}

int main() {
    int start, target;
    cin>>start>>target;
    
    queue<pair<int, int>> poses;
    poses.push({start, 0});

    vector<int> cache(1000000, -1);
    cache[start]=0;

    while(!poses.empty()) {
        int pos=poses.front().first;
        int times=poses.front().second;
        poses.pop();

        for(int i=0; i<3; i++) {
            int nextPos;
            if(i==0) {
                nextPos=pos*2;
            }
            else if(i==1) {
                nextPos=pos+1;
            }
            else {
                nextPos=pos-1;
            }
            
            if(pos<0 || (pos>target && i!=2))
                continue;
            if(cache[nextPos]!=-1)
                continue;
            
            cache[nextPos]=times+1;
            if(nextPos==target)
                break;

            poses.push({nextPos, times+1});
        }
    }
    cout<<cache[target]<<"\n";
    printRoad(cache, target, cache[target]);
}
```
<br/>

>### 회고
>이번 문제는 두개의 부분문제를 풀어야 했다. 우선 동생이 있는 좌표까지 가는 최소 시간을 찾아야 하고, 다음으로 이때의 경로를 찾아야 한다.
>최소 시간을 구하는 것은 BFS를 이용해 쉽게 해결할 수 있었고, 이때의 경로는 DP에서처럼 cache 배열을 만들어 배열에 각 위치까지의 최소 시간을 저장하도록 하고,
>동생의 좌표까지 최소 시간을 구하고 나면, cache에 저장된 시간을 이용해 경로를 역으로 추적하도록 하였다.
>이때 경로를 출력한 후 재귀함수를 호출하면 방문 순서가 역순이 되므로, 재귀함수를 먼저 호출하고, 나중에 출력하여 재귀함수가 호출된 역순으로 경로가 호출되도록 하였다.