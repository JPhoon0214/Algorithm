#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

void getDisToCurrDot(int targetY, int targetX, vector<pair<int, int> >& dots, vector<int>& storeDis) {
    for(int i=0; i<dots.size(); i++) {
        int ret=abs(targetY-dots[i].second)+abs(targetX-dots[i].first);
        storeDis.push_back(ret);
    }
}

void getDis(vector<pair<int, int> >& dots, vector<vector<vector<int> > >& shortestLen) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            getDisToCurrDot(dots[i].second, dots[j].first, dots, shortestLen[i][j]);
            sort(shortestLen[i][j].begin(), shortestLen[i][j].end());
        }
    }
}

int getRet(vector<vector<vector<int> > >& shortestLen, int toSelect) {
    int totalRet=987654321;
    int targetx, targety;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int ret=0;
            for(int selected=0; selected<toSelect; selected++) {
                ret+=shortestLen[i][j][selected];
            }
            if(totalRet>ret) {
                totalRet=ret;
            }
            totalRet=min(totalRet, ret);
        }
    }
    return totalRet;
}

int main() {
    cin>>n;
    vector<vector<vector<int> > > shortestLen(n, vector<vector<int> >(n));

    vector<pair<int, int> > dots(n);
    for(int i=0; i<n; i++) cin>>dots[i].first>>dots[i].second;

    getDis(dots, shortestLen);

    for(int i=0; i<n; i++) {
        cout<<getRet(shortestLen, i+1)<<" ";
    }    
}