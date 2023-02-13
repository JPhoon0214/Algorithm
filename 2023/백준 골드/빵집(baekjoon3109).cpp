#include <iostream>
#include <vector>

using namespace std;

int row, column;

int getRet(vector<string>& map, int x, int y, vector<vector<bool>>& visited) {
    if(x==column-1) {
        return 1;
    }
    
    visited[y][x]=true;

    int ret=0;
    for(int i=-1; i<2; i++) {
        int currY=y+i;
        int currX=x+1;

        if(currY<0 || currY>row-1) {
            continue;
        }
        if(map[currY][currX]=='x' || visited[currY][currX]) {
            continue;
        }
        ret=getRet(map, currX, currY, visited);
        if(ret!=0) {
            break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>row>>column;
    vector<string> map(row);
    for(int i=0; i<row; i++) {
        cin>>map[i];
    }

    vector<vector<bool>> visited(row, vector<bool>(column, false));

    int ret=0;
    for(int i=0; i<row; i++) {
        ret+=getRet(map, 0, i, visited);
    }
    cout<<ret;
}