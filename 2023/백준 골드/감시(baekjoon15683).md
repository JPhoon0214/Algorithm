감시
====
<br/>

>### 문제 유형/난이도
>골드4 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/15683https://www.acmicpc.net/problem/15683">문제 바로 가기(baekjoon 1568315683)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int height, width;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};

void move(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    if(y<0 || y>height-1 || x<0 || x>width-1) {
        return;
    }
    if(map[y][x]==6) {
        return;
    }
    
    visited[y][x]=true;
    int nextY=y+dy[direction];
    int nextX=x+dx[direction];
    
    move(map, visited, nextY, nextX, direction);
}

void firstCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
}

void secondCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+2)%2);
}

void thirdCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+1)%4);
}

void fourthCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+1)%4);
    move(map, visited, y, x, (direction+2)%4);
}

void fifthCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+1)%4);
    move(map, visited, y, x, (direction+2)%4);
    move(map, visited, y, x, (direction+3)%4);
}

int getMin(vector<vector<int>>& map, int y, int x) {
    if(x==width) {
        y++; x=0;
    }
    if(y==height) {
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                if(map[i][j]/10==1) {
                    firstCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==2) {
                    secondCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==3) {
                    thirdCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==4) {
                    fourthCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==5) {
                    fifthCam(map, visited, i, j, map[i][j]%10);
                }
            }
        }
        
        int ret=0;
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                if(!visited[i][j] && map[i][j]==0)
                ret++;
            }
        }
        return ret;
    }    
    
    if(map[y][x]!=0 && map[y][x]!=6) {
        int ret=987654321;
        int temp=map[y][x];
        for(int i=0; i<4; i++) {
            map[y][x]=map[y][x]*10+i;
            ret=min(getMin(map, y, x+1), ret);
            map[y][x]=temp;
        }
        return ret;
    }
    else {
        return getMin(map, y, x+1);
    }
}

int main() {    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>height>>width;

    vector<vector<int>> map(height, vector<int>(width));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }
    cout<<getMin(map, 0, 0);
}#include <iostream>
#include <vector>

using namespace std;

int height, width;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};

void move(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    if(y<0 || y>height-1 || x<0 || x>width-1) {
        return;
    }
    if(map[y][x]==6) {
        return;
    }
    
    visited[y][x]=true;
    int nextY=y+dy[direction];
    int nextX=x+dx[direction];
    
    move(map, visited, nextY, nextX, direction);
}

void firstCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
}

void secondCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+2)%2);
}

void thirdCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+1)%4);
}

void fourthCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+1)%4);
    move(map, visited, y, x, (direction+2)%4);
}

void fifthCam(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int direction) {
    move(map, visited, y, x, direction);
    move(map, visited, y, x, (direction+1)%4);
    move(map, visited, y, x, (direction+2)%4);
    move(map, visited, y, x, (direction+3)%4);
}

int getMin(vector<vector<int>>& map, int y, int x) {
    if(x==width) {
        y++; x=0;
    }
    if(y==height) {
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                if(map[i][j]/10==1) {
                    firstCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==2) {
                    secondCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==3) {
                    thirdCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==4) {
                    fourthCam(map, visited, i, j, map[i][j]%10);
                }
                else if(map[i][j]/10==5) {
                    fifthCam(map, visited, i, j, map[i][j]%10);
                }
            }
        }
        
        int ret=0;
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                if(!visited[i][j] && map[i][j]==0)
                ret++;
            }
        }
        return ret;
    }    
    
    if(map[y][x]!=0 && map[y][x]!=6) {
        int ret=987654321;
        int temp=map[y][x];
        for(int i=0; i<4; i++) {
            map[y][x]=map[y][x]*10+i;
            ret=min(getMin(map, y, x+1), ret);
            map[y][x]=temp;
        }
        return ret;
    }
    else {
        return getMin(map, y, x+1);
    }
}

int main() {    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>height>>width;

    vector<vector<int>> map(height, vector<int>(width));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }
    cout<<getMin(map, 0, 0);
}
```
<br/>

>### 회고
>>난이도에 비해 구현이 조금 어려웠던 것 같다. 어떻게 구현할지 고민하다 어쩔 수 없이 일일히 함수로 만들어 구현했다.난이도에 비해 구현이 ㅈ고ㅡㅁ