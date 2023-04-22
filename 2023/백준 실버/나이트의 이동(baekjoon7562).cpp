#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};

struct Pos {
    int x;
    int y;
    int times;
};

int bfs(int startX, int startY, int targetX, int targetY, int sideLen) {
    vector<vector<bool>> visited(sideLen, vector<bool>(sideLen, false));

    queue<Pos> poses;
    poses.push({startX, startY, 0});
    
    visited[startY][startX]=true;

    while(!poses.empty()) {
        int currX=poses.front().x;
        int currY=poses.front().y;
        int currTimes=poses.front().times;

        poses.pop();

        if(currX==targetX && currY==targetY) return currTimes;

        for(int i=0; i<8; i++) {
            int nextX=currX+dx[i];
            int nextY=currY+dy[i];

            if(nextX<0 || nextX>sideLen-1 || nextY<0 || nextY>sideLen-1) continue;
            if(visited[nextY][nextX]) continue;
            
            visited[nextY][nextX]=true;

            poses.push({nextX, nextY, currTimes+1});
        }
    }
}

int main() {
    int testCase;
    cin>>testCase;

    for(testCase; testCase>0; testCase--) {
        int sideLen;
        cin>>sideLen;

        int startX, startY, endX, endY;
        cin>>startX>>startY>>endX>>endY;

        cout<<bfs(startX, startY, endX, endY, sideLen)<<"\n";
    }
}