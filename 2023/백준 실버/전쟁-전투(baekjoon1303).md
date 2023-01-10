전쟁-전투
====
<br/>

>### 문제 유형/난이도
>실버1 / DFS, BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1303">문제 바로 가기(baekjoon 1303)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int height, width;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int getLinked(int y, int x, char target, vector<string>& map, vector<vector<bool>>& visited) {
    if(x<0 || x>width-1 || y<0 || y>height-1)
        return 0;
    if(visited[y][x])
        return 0;
    if(map[y][x]!=target)
        return 0;
    
    visited[y][x]=true;
    int ret=1;
    for(int i=0; i<4; i++) {
        ret+=getLinked(y+dy[i], x+dx[i], target, map, visited);
    }
    return ret;
}

int main() {
    cin>>width>>height;
    vector<string> map(height);
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    for(int i=0; i<height; i++) {
        cin>>map[i];
    }

    int ourPower=0;
    int enemyPower=0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(!visited[i][j]) {
                if(map[i][j]=='W') {
                    int ret=getLinked(i, j, 'W', map, visited);
                    ourPower+=ret*ret;
                }
                else {
                    int ret=getLinked(i, j, 'B', map, visited);
                    enemyPower+=ret*ret;
                }
            }
        }
    }
    cout<<ourPower<<" "<<enemyPower;
}
```
<br/>

>### 회고
>실버 문제라는 것을 감안하더라도 난이도가 높지 않은 문제였다.
>같은 색의 옷을 입은 사람의 그룹을 탐색을 통해 하나 하나 찾아주면 되었는데, 이때 DFS를 사용하든 BFS를 사용하든 큰 상관은 없어 보인다. 하지만 DFS가 상대적으로 구현이 간단하다고 생각해 DFS로 구현하였다. DFS의 탐색 순서는 현재 위치로부터 오른쪽, 위쪽, 왼쪽, 아래 순으로 탐색하였는데, 오른쪽, 위쪽, 왼쪽, 아래의 순서는 상관이 없지만, 이런 탐색 방식으로 푸는 것이 문제를 가장 간단하게 풀 수 있을 것 같았다. 또한 visited 벡터에 방문 여부를 저장해 중복 방문을 피했다. 