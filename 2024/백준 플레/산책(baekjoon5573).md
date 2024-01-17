산책
====

>### 문제 유형/난이도
>플레3 / DP

>### 문제
> <a href="https://www.acmicpc.net/problem/5573">문제 바로 가기(baekjoon 5573)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

const int dx[2]={0, 1};
const int dy[2]={1, 0};

vector<vector<int> > cache(1001, vector<int>(1001, -1));
int height, width;

int saveCache(vector<vector<int> >& map, int x, int y) {
    if(x<0 || y<0) return 0;
    if(cache[y][x]!=-1) return cache[y][x];


    int upVisited=0, leftVisited=0;
    if(y-1>=0 && map[y-1][x]==0) upVisited=(saveCache(map, x, y-1)+1)/2;
    else upVisited=saveCache(map, x, y-1)/2;

    if(x-1>=0 && map[y][x-1]==1) leftVisited=(saveCache(map, x-1, y)+1)/2;
    else leftVisited=saveCache(map, x-1, y)/2;

    return cache[y][x]=upVisited+leftVisited;
}

void findNotCalc(vector<vector<int> >& map) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(cache[i][j]==-1) {
                saveCache(map, j, i);
            }
        }
    }
}

void findPos(int& y, int& x, vector<vector<int> >& map) {
    if(y==height || x==width) return;

    int initStatus=map[y][x];
    
    if(cache[y][x]%2==1) {
        y+=dy[initStatus];
        x+=dx[initStatus];
    }
    else {
        y+=dy[(initStatus+1)%2];
        x+=dx[(initStatus+1)%2];
    }
    findPos(y, x, map);
}


int main() {
    int input;
    cin>>height>>width>>input;

    vector<vector<int> > map(height, vector<int>(width));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }

    cache[0][0]=input;
    findNotCalc(map);

    int x=0, y=0;
    findPos(y, x, map);

    cout<<y+1<<" "<<x+1;
}
```

>### 회고
>올해 첫 번째 플레 문제. 전역하면서 공부할게 많아져서 예전처럼 진득하게 앉아서 알고리즘을 풀지 못했다. 그래서 푸는 문제가 실버나 골드 문제 뿐이었는데, 간만에 플레 문제를 풀어보고 싶어 풀게 되었다. 사실 처음 아이디어를 생각하고 이렇게 쉽게 풀릴리가 없다 생각했는데 그대로 풀려 버렸다.  
뭔가 기분은 좋다.  
각 지점을 몇번 방문하는지 횟수를 세는 함수를 만들고 이를 저장했다. n번 산책을 할 동안 각 지점을 몇번 방문하는지 알면 n번째 산책에서 경로를 알 수 있기 때문에 답을 구할 수 있었다. 다만 산책에서 마지막 지점은 일정하지 않기 때문에 모든 지점을 순회하면서 만약 그 지점이 몇번 방문했는지 카운트가 안 됐다면 DP를 이용해 이를 알아내는 방식으로 구했다. 글로 설명을 잘 못했는데 문제를 읽고 코드를 보는게 나중에 봤을때 오히려 이해하기 쉬울거 같기도 하다.  
