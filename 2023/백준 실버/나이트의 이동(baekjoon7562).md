나이트의 이동
====
<br/>

>### 문제 유형/난이도
>실버1 / BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/7562">문제 바로 가기(baekjoon 7562)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};

struct Pos {
    int x;
    int y;
    int times;
};

int bfs(int startX, int startY, int targetX, int targetY, int sideLen) {
    vector<vector<bool>> visited(sideLen, vector<bool>(sideLen, false));

    queue<Pos> poses;
    poses.push({startX, startY, 0});
    
    visited[startY][startX]=true;

    while(!poses.empty()) {
        int currX=poses.front().x;
        int currY=poses.front().y;
        int currTimes=poses.front().times;

        poses.pop();

        if(currX==targetX && currY==targetY) return currTimes;

        for(int i=0; i<8; i++) {
            int nextX=currX+dx[i];
            int nextY=currY+dy[i];

            if(nextX<0 || nextX>sideLen-1 || nextY<0 || nextY>sideLen-1) continue;
            if(visited[nextY][nextX]) continue;
            
            visited[nextY][nextX]=true;

            poses.push({nextX, nextY, currTimes+1});
        }
    }
}

int main() {
    int testCase;
    cin>>testCase;

    for(testCase; testCase>0; testCase--) {
        int sideLen;
        cin>>sideLen;

        int startX, startY, endX, endY;
        cin>>startX>>startY>>endX>>endY;

        cout<<bfs(startX, startY, endX, endY, sideLen)<<"\n";
    }
}
```
<br/>

>### 회고
>너비 우선 탐색 꽤 오랫동안 안 풀어서 약간씩 실수가 있다.  
>곧 코딩 테스트가 있는데 다시 감을 잡을 필요가 있다.  
>항상 현재 위치에서 목표 위치에 도달할 수 있다는 전제 하에 코드를 작성했다.