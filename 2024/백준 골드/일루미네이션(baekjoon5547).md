일루미네이션
====  

>### 문제 유형/난이도
>골드4 / DFS  

>### 문제
> <a href="https://www.acmicpc.net/problem/5547">문제 바로 가기(baekjoon 5547)</a>  

>### 코드
```c++
#include <iostream>
#include <vector>

using namespace std;

int height, width;

const int dx[2][6] = {
    {-1, 0, 1, 0, -1, -1},
    {0, 1, 1, 1, 0, -1}
};

const int dy[2][6] = {
    {-1, -1, 0, 1, 1, 0},
    {-1, -1, 0, 1, 1, 0}
};

int searchAndGetLen(vector<vector<int> >& map, vector<vector<bool> >& visited, int y, int x) {
    if(y<0 || y>height+1 || x<0 || x>width+1) return 0;
    if(map[y][x]==1) return 1;
    if(visited[y][x]) return 0;

    visited[y][x]=true;
    int ret=0;
    
    for(int i=0; i<6; i++) {
        int nextX=x+dx[y%2][i];
        int nextY=y+dy[y%2][i];

        ret+=searchAndGetLen(map, visited, nextY, nextX);
    }

    return ret;
}

int getTotalSideLen(vector<vector<int> >& map) {
    vector<vector<bool> > visited(height+2, vector<bool>(width+2, false));

    int ret=0;

    for(int i=0; i<height+2; i++) {
        for(int j=0; j<width+2; j++) {
            if(i==0 || j==0 || i==height+1 || j==width+1) {
                if(visited[i][j]) continue;

                ret+=searchAndGetLen(map, visited, i, j);
            }
        }
    }

    return ret;
}

int main() {
    cin>>width>>height;

    vector<vector<int> > map(height+2, vector<int>(width+2));
    for(int i=0; i<height+2; i++) {
        for(int j=0; j<width+2; j++) {
            if(i==0 || i==height+1 || j==0 || j==width+1) {
                map[i][j]=0;
            }
            else {
                cin>>map[i][j];
            }
        }
    }

    cout<<getTotalSideLen(map);
}
```  

>### 회고
육각형이라니... 익숙하지 않아서 조금 당황스러웠다.  
이 문제를 어렵게 만드는 요소는 두개라 생각하는데, 우선 열의 인덱스가 짝수인지 홀수인지에 따라 이동할 수 있는 다른 정육각형의 인덱스가 달라지기 때문에 탐색 코드를 짜기 조금 곤란할 뿐만 아니라 테스트하기가 어렵고, 두번째로 건물로 둘러쌓인 내부를 처리하기 곤란하다는 것이다.  
우선 첫번째 문제는 따로 이차원 이동용 상수를 두어 해결했다. 순서는 좌상, 우상, 우 우하, 좌하, 좌 순이다.  
두번째 문제는 주어진 건물 배치의 가장자리에서 탐색을 하도록 하여 해결했다. 건물로 둘러쌓인 부분은 이런 방식으로 할 경우 닿지 않기 때문에 자연스럽게 해결된다.  
다만 건물과 빈 공간 정육각형이 인접한 경우 뿐만 아니라 건물 정육각형이 인접한 부분이 없는 경우에도 장식을 해줘야 하는데, 이를 따로 처리하기 어렵기 때문에 처음 주어진 건물 위치 지도 테두리에 빈 정육면체를 한번 둘렀다. 부수적인 이점으로 가장자리에서 탐색을 할 때 해당 자리가 건물인지 빈 공간인지 판별할 필요가 없다. 방금 깨달은 사실인데 getTotalSideLen에서 반복문은 필요 없고, 가장자리 임의에 자리 한곳에서 탐색을 시작하기만 하면 됐었다. 처음에 테두리에 빈 공간을 두를 생각을 안했을 때 짠 코드라 미쳐 생각을 못했다.  