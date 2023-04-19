#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int sideLen, lowerGap, upperGap;

int checkToMove(int indexX, int indexY, vector<vector<int>>& map, vector<vector<bool>>& visited, vector<pair<int, int>>& currVisit) {
    currVisit.push_back({indexX, indexY});
    visited[indexY][indexX]=true;

    int ret=map[indexY][indexX];

    for(int i=0; i<4; i++) {
        int currY=indexY+dy[i];
        int currX=indexX+dx[i];

        if(currY<0 || currY>sideLen-1 || currX<0 || currX>sideLen-1) continue;
        if(visited[currY][currX]) continue;

        int gap=abs(map[indexY][indexX]-map[currY][currX]);

        if(gap<lowerGap || gap>upperGap) continue;

        ret+=checkToMove(currX, currY, map, visited, currVisit);
    }
    return ret;
}

void setPeople(int peopleNum, vector<pair<int, int>>& currVisit, vector<vector<int>>& map) {
    for(int i=0; i<currVisit.size(); i++) {
        int currX=currVisit[i].first;
        int currY=currVisit[i].second;
        
        map[currY][currX]=peopleNum/currVisit.size();
    }
}

int main() {
    cin>>sideLen>>lowerGap>>upperGap;

    vector<vector<int>> map(sideLen, vector<int>(sideLen));
    for(int i=0; i<sideLen; i++) {
        for(int j=0; j<sideLen; j++) {
            cin>>map[i][j];
        }
    }

    int ret=0;
    
    while(true) {
        bool noMove=true;
        
        vector<vector<bool>> visited(sideLen, vector<bool>(sideLen, false));

        for(int i=0; i<sideLen; i++) {
            for(int j=0; j<sideLen; j++) {
                vector<pair<int, int>> currVisit;
                if(visited[i][j]) continue;

                int peopleNum=checkToMove(j, i, map, visited, currVisit);
                setPeople(peopleNum, currVisit, map);
                
                if(currVisit.size()>1) {
                    noMove=false;
                }
            }
        }

        if(noMove) break;
        
        ret++;
    }

    cout<<ret;
}