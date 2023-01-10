#include <iostream>
#include <vector>

using namespace std;

int height, width;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int getLinked(int y, int x, char target, vector<string>& map, vector<vector<bool>>& visited) {
    if(x<0 || x>width-1 || y<0 || y>height-1)
        return 0;
    if(visited[y][x])
        return 0;
    if(map[y][x]!=target)
        return 0;
    
    visited[y][x]=true;
    int ret=1;
    for(int i=0; i<4; i++) {
        ret+=getLinked(y+dy[i], x+dx[i], target, map, visited);
    }
    return ret;
}

int main() {
    cin>>width>>height;
    vector<string> map(height);
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    for(int i=0; i<height; i++) {
        cin>>map[i];
    }

    int ourPower=0;
    int enemyPower=0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(!visited[i][j]) {
                if(map[i][j]=='W') {
                    int ret=getLinked(i, j, 'W', map, visited);
                    ourPower+=ret*ret;
                }
                else {
                    int ret=getLinked(i, j, 'B', map, visited);
                    enemyPower+=ret*ret;
                }
            }
        }
    }
    cout<<ourPower<<" "<<enemyPower;
}