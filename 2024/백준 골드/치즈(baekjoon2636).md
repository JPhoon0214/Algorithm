치즈
====
<br/>

>### 문제 유형/난이도
>골드4 / DFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2636">문제 바로 가기(baekjoon 2636)</a>  

>### 코드
```c++
#include <iostream>
#include <vector>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int height, width;

int cheeseNum(int y, int x, vector<vector<int> >& map, vector<vector<bool> >& visited) {
    if(x<0 || x>width-1 || y<0 || y>height-1) return 0;
    if(visited[y][x]) return 0;
    if(map[y][x]>0) {
        map[y][x]--;
        visited[y][x]=true;
        return 1;
    }

    visited[y][x]=true;

    int ret=0;

    for(int i=0; i<4; i++) {
        int nextY=y+dy[i], nextX=x+dx[i];
        ret+=cheeseNum(nextY, nextX, map, visited);
    }

    return ret;
}

int getTime(vector<vector<int> >& map, int& lastCheeseSize) {
    int time=0;
    while(true) {
        vector<vector<bool> > visited(height, vector<bool>(width, false));
        int currCheeseSize=cheeseNum(0, 0, map, visited);
        if(currCheeseSize==0) break;

        lastCheeseSize=currCheeseSize;
        time++;
    }
    return time;
}

int main() {
    cin>>height>>width;
    vector<vector<int> > map(height, vector<int>(width));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }

    int lastCheeseSize=0;

    cout<<getTime(map, lastCheeseSize)<<"\n"<<lastCheeseSize;
}
```

>### 회고
2638 문제 난이도 기여 하다가 2636 문제랑 똑같다고 해서 한번 풀어봤다. 난이도가 한단계 낮은 만큼 한 면만 치즈에 맞닿으면 녹기 때문에 풀기 더 쉬웠다. 이외에 2638문제와 크게 다르지 않았다.