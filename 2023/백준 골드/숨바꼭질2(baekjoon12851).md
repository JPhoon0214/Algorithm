숨바꼭질2
====
<br/>

>### 문제 유형/난이도
>골드4 / BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/12851">문제 바로 가기(baekjoon 12851)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>> poses;
vector<int> minMoves(1000000, 987654321);

int main() {
    int start, target;
    cin>>start>>target;

    int minMove=987654321;
    int caseNum=0;

    if(start==target) {
        cout<<0<<"\n";
        cout<<1;        
    }
    else {
        poses.push({start, 0});
        while(!poses.empty()) {
            int pos=poses.front().first;
            int time=poses.front().second;
            poses.pop();
    
            if(time>=minMove || (0<=pos && pos<1000000 && minMoves[pos]<time))
                continue;
            
            minMoves[pos]=time;
    
            long long next;
            if(pos>0) {
                next=pos-1;
                if(next==target) {
                    minMove=time+1;
                    caseNum++;
                }
                else {
                    poses.push({next, time+1});
                }
            }
            if(pos<target) {
                next=pos+1;
                if(next==target) {
                    minMove=time+1;
                    caseNum++;
                }
                else {
                    poses.push({next, time+1});
                }
    
                next=pos*2;
                if(next==target) {
                    minMove=time+1;
                    caseNum++;
                }
                else {
                    poses.push({next, time+1});
                }
            }
        }
        cout<<minMove<<"\n";
        cout<<caseNum;        
    }
}

```
<br/>

>### 회고
>가장 적은 시행횟수로 원하는 답을 찾는 전형적인 BFS문제이다. 그럼에도 나는 이 문제를 푸는데 매우 애를 먹었는데
> >1. 원하는 답을 찾을 때까지 단순히 너비 우선 탐색을 진행할 경우, 시간 초과에 메모리 초과가 발생한다. 코드를 짜기 전에 이를 예상하지 못했고, 이후 이 문제를 해결하기 위해 배열에 각 숫자까지 오는데 걸린 최소 횟수를 저장하고, 이보다 오래 걸린 입력이 들어오면 continue하는 방식으로 문제를 해결했다. 처음에 생각지 못한 부분이었기 때문에 코드가 조금 더러워졌다.
> >2. 위치의 상한값과 하한값이 주어지지 않았다. 물론 수빈이의 좌표가 동생의 좌표보다 커진다면, +1을 하거나 *2를 하지 않는 것이 무조건 좋다는 것은 쉽게 알 수 있지만, 그럼에도 좌표가 음수가 될 수 있는지, 커진다면 어디까지 커질 수 있을 지 등을 알기 쉽지 않아 매우 보수적으로 코드를 작성해야 했다.
>
>문제를 풀기 전에 내가 생각한 알고리즘이 시간제한과 메모리 제한을 넘지 않을지 조금 더 꼼꼼하게 따져볼 필요가 있을 것 같다.