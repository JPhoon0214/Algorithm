#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;

vector<int> allNums;

vector<int> dxs;
vector<int> dys;

void startThisPlace(int currX, int currY, int dx, int dy, int bef, vector<string>& map) {
    int nextX=currX+dx;
    int nextY=currY+dy;

    if(nextX<0 || nextX>m-1 || nextY<0 || nextY>n-1) return;

    int curr=10*bef+(map[nextY][nextX]-'0');
    allNums.push_back(curr);
    startThisPlace(currX+dx, currY+dy, dx, dy, curr, map);
}

void makeCases(vector<string>& map) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            allNums.push_back(map[i][j]-'0');
            if(map[i][j]=='0') continue;

            for(int k=0; k<dxs.size(); k++) {
                startThisPlace(j, i, dxs[k], dys[k], map[i][j]-'0', map);
            }
        }
    }
}

int main() {
    cin>>n>>m;
    vector<string> map(n);

    for(int i=0; i<n; i++) cin>>map[i];

    for(int i=-n; i<=n; i++) {
        for(int j=-m; j<=m; j++) {
            if(i==0 && j==0) continue;

            dxs.push_back(j);
            dys.push_back(i);
        }
    }

    makeCases(map);

    sort(allNums.begin(), allNums.end());
    
    int allNumPointer=0;
    int ret=-1;
    int i=0;

    while(allNumPointer<allNums.size()) {
        int currPow=pow(i, 2);

        if(currPow==allNums[allNumPointer]) {
            ret=currPow;
            allNumPointer++;
            i++;
        }             
        else if(currPow<allNums[allNumPointer]) {
            i++;
        }
        else {
            allNumPointer++;
        }
    }

    cout<<ret;
}