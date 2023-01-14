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