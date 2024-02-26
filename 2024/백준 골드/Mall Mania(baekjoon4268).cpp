#include <iostream>
#include <queue>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct Pos {
    int y;
    int x;
    int moveDis;
};

int getDis(vector<Pos>& shop1, vector<vector<bool> >& target, vector<vector<bool> >& visited) {
    queue<Pos> q;

    for(int i=0; i<shop1.size(); i++) {
        Pos pos = {shop1[i].y, shop1[i].x, 0};

        q.push(pos);
    }

    int ret=0;

    while(!q.empty()) {
        Pos pos = q.front();
        q.pop();

        if(pos.x<0 || pos.x>1999 || pos.y<0 || pos.y>1999) continue;

        if(visited[pos.y][pos.x]) continue;
        visited[pos.y][pos.x] = true;

        if(target[pos.y][pos.x]) {
            ret = pos.moveDis;
            break;
        }

        for(int i=0; i<4; i++) {
            int nextX = pos.x+dx[i];
            int nextY = pos.y+dy[i];

            Pos nextPos = {nextY, nextX, pos.moveDis+1};
            q.push(nextPos);
        }
    }

    return ret;
}

int main() {
    while(true) {
        int spotNum1, spotNum2;
        cin>>spotNum1;

        if(spotNum1==0) break;

        vector<Pos> shop1(spotNum1);

        for(int i=0; i<spotNum1; i++) {
            cin>>shop1[i].y>>shop1[i].x;
        }

        cin>>spotNum2;
        vector<vector<bool> > target(2000, vector<bool>(2000, false));
        vector<vector<bool> > visited(2000, vector<bool>(2000, false));

        for(int i=0; i<spotNum2; i++) {
            int targetY, targetX;
            cin>>targetY>>targetX;

            target[targetY][targetX]=true;
        }

        cout<<getDis(shop1, target, visited)<<"\n";
    }
}