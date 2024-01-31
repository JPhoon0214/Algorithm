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