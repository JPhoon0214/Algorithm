알고스팟
====
<br/>

>### 문제 유형/난이도
>골드4 / 0-1 BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1261">문제 바로 가기(baekjoon 1261)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

struct Pos {
    int x;
    int y;
    int breakWall;
};

int main() {
    int width, height;
    cin>>width>>height;
    vector<string> map(height);
    for(int i=0; i<height; i++) {
        cin>>map[i];
    }

    deque<Pos> poses;
    poses.push_back({0, 0, 0});

    vector<vector<bool>> visited(height, vector<bool>(width, false));

    int ret=-1;
    while(!poses.empty()) {
        if(ret!=-1)
            break;

        int x=poses.front().x, y=poses.front().y, breakWall=poses.front().breakWall;
        poses.pop_front();

        for(int i=0; i<4; i++) {
            int currX=x+dx[i];
            int currY=y+dy[i];

            if(currX<0 || currX>width-1 || currY<0 || currY>height-1)
                continue;
            if(visited[currY][currX])
                continue;

            int nextBreak=map[currY][currX]=='1' ? breakWall+1 : breakWall;
            if(currY==height-1 && currX==width-1) {
                ret=nextBreak;
                break;
            }
            
            visited[currY][currX]=true;

            if(map[currY][currX]=='1')
                poses.push_back({currX, currY, nextBreak});
            else
                poses.push_front({currX, currY, nextBreak});
        }
    }

    if(ret==-1)
        cout<<0;
    else
        cout<<ret;
}
```
<br/>

>### 회고
>0-1 너비우선탐색으로 풀어보는 두번째 문제이다. 아직 다른 사람들이 대체적으로 어떻게 구현하는지 찾아보지 않고, 내 나름대로 이해한 대로 코드를 짜보고 있는데, 역시 탐색을 시작할 때부터 그 위치가 찾는 값일 경우가 구현하기가 애매하다. 일단은 이런 경우는 따로 처리해주는 방식으로 코드를 짜고 있다. 0-1 BFS를 배우고 나니 관련 문제의 난이도가 많이 내려간 느낌이다. 0-1 BFS문제라는 것을 모르더라도 관련 개념이 생각날 수 있도록 열심히 문제를 더 풀어봐야겠다