인구이동
====
<br/>

>### 문제 유형/난이도
>골드5 / 그래프탐색, 너비우선탐색, 깊이우선탐색
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/16234">문제 바로 가기(baekjoon 16234)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int sideLen, lowerGap, upperGap;

int checkToMove(int indexX, int indexY, vector<vector<int>>& map, vector<vector<bool>>& visited, vector<pair<int, int>>& currVisit) {
    currVisit.push_back({indexX, indexY});
    visited[indexY][indexX]=true;

    int ret=map[indexY][indexX];

    for(int i=0; i<4; i++) {
        int currY=indexY+dy[i];
        int currX=indexX+dx[i];

        if(currY<0 || currY>sideLen-1 || currX<0 || currX>sideLen-1) continue;
        if(visited[currY][currX]) continue;

        int gap=abs(map[indexY][indexX]-map[currY][currX]);

        if(gap<lowerGap || gap>upperGap) continue;

        ret+=checkToMove(currX, currY, map, visited, currVisit);
    }
    return ret;
}

void setPeople(int peopleNum, vector<pair<int, int>>& currVisit, vector<vector<int>>& map) {
    for(int i=0; i<currVisit.size(); i++) {
        int currX=currVisit[i].first;
        int currY=currVisit[i].second;
        
        map[currY][currX]=peopleNum/currVisit.size();
    }
}

int main() {
    cin>>sideLen>>lowerGap>>upperGap;

    vector<vector<int>> map(sideLen, vector<int>(sideLen));
    for(int i=0; i<sideLen; i++) {
        for(int j=0; j<sideLen; j++) {
            cin>>map[i][j];
        }
    }

    int ret=0;
    
    while(true) {
        bool noMove=true;
        
        vector<vector<bool>> visited(sideLen, vector<bool>(sideLen, false));

        for(int i=0; i<sideLen; i++) {
            for(int j=0; j<sideLen; j++) {
                vector<pair<int, int>> currVisit;
                if(visited[i][j]) continue;

                int peopleNum=checkToMove(j, i, map, visited, currVisit);
                setPeople(peopleNum, currVisit, map);
                
                if(currVisit.size()>1) {
                    noMove=false;
                }
            }
        }

        if(noMove) break;
        
        ret++;
    }

    cout<<ret;
}
```
<br/>

>### 회고
> 태그에는 너비 우선 탐색이라 되어 있었지만, 나는 깊이 우선 탐색으로 해결했다.
> 시뮬레이션 느낌으로 직접 수행해 가면서 더 이상 인구 이동이 일어나지 않을 때까지의 숫자를 세는 방식으로 문제를 해결했다.
> 그래프 문제 오랜만에 푸는데, 얼마 후에 있을 코딩 테스트에서 왠지 그래프 문제가 나올 것 같아 연습 중이다.  