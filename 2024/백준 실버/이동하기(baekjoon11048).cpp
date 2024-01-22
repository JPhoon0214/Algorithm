#include <iostream>
#include <vector>

using namespace std;

int height, width;

vector<vector<int> > cache(1000, vector<int>(1000, -1));

int getMaxCandy(int x, int y, vector<vector<int> >& map) {
    if(x==width-1 && y==height-1) return map[y][x];
    if(cache[y][x]!=-1) return cache[y][x];

    if(x>=width-1) {
        return cache[y][x]=getMaxCandy(x, y+1, map)+map[y][x];
    }
    else if(y>=height-1) {
        return cache[y][x]=getMaxCandy(x+1, y, map)+map[y][x];
    }
    else {
        int ret=max(getMaxCandy(x, y+1, map), getMaxCandy(x+1, y, map));
        return cache[y][x]=ret+map[y][x];
    }
}

int main() {
    cin>>height>>width;
    vector<vector<int> > map(height, vector<int>(width));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }
    cout<<getMaxCandy(0, 0, map);
}