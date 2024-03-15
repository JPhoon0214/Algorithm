#include <iostream>
#include <vector>

using namespace std;

const int dx[2]={0, 1};
const int dy[2]={1, 0};

vector<vector<int> > cache(1001, vector<int>(1001, -1)); 
int height, width;

int saveCache(vector<vector<int> >& map, int x, int y) {
    if(x<0 || y<0) return 0;
    if(cache[y][x]!=-1) return cache[y][x];


    int upVisited=0, leftVisited=0;
    if(y-1>=0 && map[y-1][x]==0) upVisited=(saveCache(map, x, y-1)+1)/2;
    else upVisited=saveCache(map, x, y-1)/2;

    if(x-1>=0 && map[y][x-1]==1) leftVisited=(saveCache(map, x-1, y)+1)/2;
    else leftVisited=saveCache(map, x-1, y)/2;

    return cache[y][x]=upVisited+leftVisited;
}

void findNotCalc(vector<vector<int> >& map) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(cache[i][j]==-1) {
                saveCache(map, j, i);
            }
        }
    }
}

void findPos(int& y, int& x, vector<vector<int> >& map) {
    if(y==height || x==width) return;

    int initStatus=map[y][x];
    
    if(cache[y][x]%2==1) {
        y+=dy[initStatus];
        x+=dx[initStatus];
    }
    else {
        y+=dy[(initStatus+1)%2];
        x+=dx[(initStatus+1)%2];
    }
    findPos(y, x, map);
}


int main() {
    int input;
    cin>>height>>width>>input;

    vector<vector<int> > map(height, vector<int>(width));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }

    cache[0][0]=input;
    findNotCalc(map);

    int x=0, y=0;
    findPos(y, x, map);

    cout<<y+1<<" "<<x+1;
}
