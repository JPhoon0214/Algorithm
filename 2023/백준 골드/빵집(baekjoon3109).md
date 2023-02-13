빵집
====
<br/>

>### 문제 유형/난이도
>골드2 / 그리디, 그래프 탐색
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/3109">문제 바로 가기(baekjoon 3109)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int row, column;

int getRet(vector<string>& map, int x, int y, vector<vector<bool>>& visited) {
    if(x==column-1) {
        return 1;
    }
    
    visited[y][x]=true;

    int ret=0;
    for(int i=-1; i<2; i++) {
        int currY=y+i;
        int currX=x+1;

        if(currY<0 || currY>row-1) {
            continue;
        }
        if(map[currY][currX]=='x' || visited[currY][currX]) {
            continue;
        }
        ret=getRet(map, currX, currY, visited);
        if(ret!=0) {
            break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>row>>column;
    vector<string> map(row);
    for(int i=0; i<row; i++) {
        cin>>map[i];
    }

    vector<vector<bool>> visited(row, vector<bool>(column, false));

    int ret=0;
    for(int i=0; i<row; i++) {
        ret+=getRet(map, 0, i, visited);
    }
    cout<<ret;
}
```
<br/>

>### 회고
>그리디가 적용된 문제이긴 했지만, 그리디 아이디어 자체는 그리 어렵지 않았다. 파이프가 연결되어 있는 가장 상층부터 다음 연결된 지점을 찾는다면, 다른 파이프들과 겹치지 않게 다음에 연결할 수 있는 지점 중 가능한 위에 위치한 지점과 연결하면 되었다. 그래프 구현이 조금 더 어려웠는데, visited으로 방문 여부를 저장하여 이미 연결되었거나 혹은 목표 지점에 도달할 수 없는 경로인지 판별하도록 하였다.