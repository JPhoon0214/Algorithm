#include <iostream>
#include <vector>

using namespace std;

int height, width;

const int dx[2][6] = {
    {-1, 0, 1, 0, -1, -1},
    {0, 1, 1, 1, 0, -1}
};

const int dy[2][6] = {
    {-1, -1, 0, 1, 1, 0},
    {-1, -1, 0, 1, 1, 0}
};

int searchAndGetLen(vector<vector<int> >& map, vector<vector<bool> >& visited, int y, int x) {
    if(y<0 || y>height+1 || x<0 || x>width+1) return 0;
    if(map[y][x]==1) return 1;
    if(visited[y][x]) return 0;

    visited[y][x]=true;
    int ret=0;
    
    for(int i=0; i<6; i++) {
        int nextX=x+dx[y%2][i];
        int nextY=y+dy[y%2][i];

        ret+=searchAndGetLen(map, visited, nextY, nextX);
    }

    return ret;
}

int getTotalSideLen(vector<vector<int> >& map) {
    vector<vector<bool> > visited(height+2, vector<bool>(width+2, false));

    int ret=0;

    for(int i=0; i<height+2; i++) {
        for(int j=0; j<width+2; j++) {
            if(i==0 || j==0 || i==height+1 || j==width+1) {
                if(visited[i][j]) continue;

                ret+=searchAndGetLen(map, visited, i, j);
            }
        }
    }

    return ret;
}

int main() {
    cin>>width>>height;

    vector<vector<int> > map(height+2, vector<int>(width+2));
    for(int i=0; i<height+2; i++) {
        for(int j=0; j<width+2; j++) {
            if(i==0 || i==height+1 || j==0 || j==width+1) {
                map[i][j]=0;
            }
            else {
                cin>>map[i][j];
            }
        }
    }

    cout<<getTotalSideLen(map);
}