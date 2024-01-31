치즈
====
<br/>

>### 문제 유형/난이도
>골드3 / DFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2638">문제 바로 가기(baekjoon 2638)</a>  

>### 코드
```c++
#include <iostream>
#include <vector>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int height, width;

bool noCheese(int y, int x, vector<vector<int> >& map, vector<vector<bool> >& visited) {
    if(x<0 || x>width-1 || y<0 || y>height-1) return true;
    if(map[y][x]>0) {
        map[y][x]--;
        visited[y][x]=true;
        return false;
    }
    if(visited[y][x]) return true;

    visited[y][x]=true;

    bool ret=true;

    for(int i=0; i<4; i++) {
        int nextY=y+dy[i], nextX=x+dx[i];
        if(!noCheese(nextY, nextX, map, visited)) {
            ret=false;
        }
    }

    return ret;
}

void oneMakeTwo(vector<vector<int> >& map) {
    const int restore[3]={0, 2, 2};

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            map[i][j]=restore[map[i][j]];
        }
    }
}

int getTime(vector<vector<int> >& map) {
    int time=0;
    while(true) {
        oneMakeTwo(map);
        vector<vector<bool> > visited(height, vector<bool>(width, false));
        if(noCheese(0, 0, map, visited)) break;

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

    cout<<getTime(map);
}
```

>### 회고
단순한 아이디어로 조금은 무식하게 풀었지만, 시간 안에 돌 것이라는 확신을 가지고 푼 문제다.  
치즈 사이의 빈 공백을 처리하기 까다로울 것 같아서, 차라리 조금 무식하더라도 가장자리는 치즈가 없다는 전제를 이용해 가장 왼쪽 가장자리부터 탐색을 하다 치즈를 만나면 탐색을 멈추도록 설계했다. 이렇게 하면 굳이 치즈 사이의 공백은 신경쓰지 않아도 괜찮다. 이렇게 할 경우 한 탐색 당 재귀함수는 최대 모든 칸을 방문한다 가정했을 때 10000개, 그리고 치즈가 녹는데 걸리는 시간은 한번에 치즈 1개씩 녹는 경우가 최소라 가정했을 때 최대 10000초가 걸린다. 물론 재귀함수를 한번 시행할 때 반복문을 돌리기 때문에 최대 4억번의 연산이 필요하다는 계산이 나온다. 시간초과가 날만하지만, 10000개의 칸을 탐색하는 경우는 치즈가 하나도 없을 경우이고, 10000초가 걸리는 경우는 모든 칸에 치즈가 있는 경우에도 이만큼 걸리진 않는다. 위 계산은 보수적으로 계산했을 경우이고 실제로는 훨씬 시간이 단축될 것이라 여겨 이렇게 풀었다.  