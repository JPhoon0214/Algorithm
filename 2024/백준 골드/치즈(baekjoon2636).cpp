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