#include <iostream>
#include <vector>

using namespace std;

const int dy[4]={1, 0, -1, 0};
const int dx[4]={0, 1, 0, -1};

int width, height;

int getMaxSpace(int x, int y, vector<string>& map, vector<bool>& visited) {
    if(x<0 || x>width-1 || y<0 || y>height-1) return 0;
    if(visited[map[y][x]-'A']) return 0;

    visited[map[y][x]-'A']=true;
    int ret=0;
    for(int i=0; i<4; i++) {
        ret=max(ret, 1+getMaxSpace(x+dx[i], y+dy[i], map, visited));
    }
    visited[map[y][x]-'A']=false;
    return ret;
}

int main() {
    cin>>height>>width;
    vector<string> map(height);
    for(int i=0; i<height; i++) cin>>map[i];

    vector<bool> visited('Z'-'A'+1, false);

    cout<<getMaxSpace(0, 0, map, visited);
}