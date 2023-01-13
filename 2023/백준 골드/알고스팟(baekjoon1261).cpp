#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

struct Pos {
    int x;
    int y;
    int breakWall;
};

int main() {
    int width, height;
    cin>>width>>height;
    vector<string> map(height);
    for(int i=0; i<height; i++) {
        cin>>map[i];
    }

    deque<Pos> poses;
    poses.push_back({0, 0, 0});

    vector<vector<bool>> visited(height, vector<bool>(width, false));

    int ret=-1;
    while(!poses.empty()) {
        if(ret!=-1)
            break;

        int x=poses.front().x, y=poses.front().y, breakWall=poses.front().breakWall;
        poses.pop_front();

        for(int i=0; i<4; i++) {
            int currX=x+dx[i];
            int currY=y+dy[i];

            if(currX<0 || currX>width-1 || currY<0 || currY>height-1)
                continue;
            if(visited[currY][currX])
                continue;

            int nextBreak=map[currY][currX]=='1' ? breakWall+1 : breakWall;
            if(currY==height-1 && currX==width-1) {
                ret=nextBreak;
                break;
            }
            
            visited[currY][currX]=true;

            if(map[currY][currX]=='1')
                poses.push_back({currX, currY, nextBreak});
            else
                poses.push_front({currX, currY, nextBreak});
        }
    }

    if(ret==-1)
        cout<<0;
    else
        cout<<ret;
}