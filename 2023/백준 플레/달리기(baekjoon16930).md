달리기
====
<br/>

>### 문제 유형/난이도
>플레3 / BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/16930">문제 바로 가기(baekjoon 16930)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Pos {
    int x;
    int y;
    int times;
};

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int height, width, moveAvail;
    cin>>height>>width>>moveAvail;
    string map[height];
    int cache[height][width];
    memset(cache, -1, sizeof(cache));

    for(int i=0; i<height; i++) {
        cin>>map[i];
    }
    int startX, startY, endX, endY;
    cin>>startY>>startX>>endY>>endX;
    
    int targetX=endX-1, targetY=endY-1;
    queue<Pos> poses;
    poses.push({startX-1, startY-1, 0});
    cache[startY-1][startX-1]=0;

    while(!poses.empty()) {
        int x=poses.front().x, y=poses.front().y, time=poses.front().times;
        poses.pop();

        for(int i=0; i<4; i++) {
            int directionX=dx[i];
            int directionY=dy[i];
            for(int j=1; j<=moveAvail; j++) {
                int currX=x+directionX*j;
                int currY=y+directionY*j;
                if(currX<0 || currX>width-1 || currY<0 || currY>height-1)
                    break;
                if(map[currY][currX]=='#')
                    break;
                if(cache[currY][currX]!=-1) {
                    if(cache[currY][currX]<time+1)
                        break;
                    else
                        continue;
                }
                cache[currY][currX]=time+1;
                poses.push({currX, currY, time+1});
            }
        }
    }
    cout<<cache[targetY][targetX];
}
```
<br/>

>### 회고
>처음 봤을 때는 왜 이 문제가 플레3일까 의아했다. 특별한 아이디어 없이 BFS로 풀면 될 것 같았기 때문이다. 조금 우려스러웠던 점은 부분문제가 1,000*1,000=1,000,000이고, 각 부분문제에서 반복문을 최대 1,000번 돌리게 되므로 시간 초과가 날 수도 있다고 생각했다. 직접 코드를 짜서 이를 확인해 보기로 했다
>코드를 짜는 것은 어렵지 않았다. 금방 코드를 작성해서 제출해 보았지만 97프로에서 시간초과 판정을 받았다. 잠시나마 기대했어서 조금 아쉬웠지만 당연한 결과라 생각했다. 코드를 조금 수정해서 이래저래 제출해 보았지만, 이후로 대여섯번정도 오답 판정을 받았다. 그러던 중 마지막으로 이미 queue에 저장된 위치로 추정되는 값이면 queue에 넣지 않도록 코드를 수정하여 결국 정답 처리를 받을 수 있었다.
>그동안 플레문제를 마주치면 어떻게 풀어나가야 할지 막막했는데, 이 문제는 푸는 방법이 간단한 대신, 최적화를 위한 노력이 조금 필요했던 것 같다.