#include <iostream>
#include <vector>

using namespace std;

int eggNum;

int getBreakEggs(vector<pair<int, int>>& eggInfos) {
    int cnt=0;
    vector<pair<int, int>>::iterator iter=eggInfos.begin();

    while(iter!=eggInfos.end()) {
        if((*iter).first<=0) cnt++;
        iter++;
    }

    return cnt;
}

int getMaxBreak(vector<pair<int, int>>& eggInfos, int currEgg) {
    if(currEgg==eggNum) {
        return getBreakEggs(eggInfos);
    }
    if(eggInfos[currEgg].first<=0) return getMaxBreak(eggInfos, currEgg+1);

    bool hit=false;
    int ret=0;
    for(int i=0; i<eggNum; i++) {
        if(i==currEgg) continue;
        if(eggInfos[i].first<=0) continue;

        hit=true;

        eggInfos[i].first-=eggInfos[currEgg].second;
        eggInfos[currEgg].first-=eggInfos[i].second;

        ret=max(ret, getMaxBreak(eggInfos, currEgg+1));

        eggInfos[i].first+=eggInfos[currEgg].second;
        eggInfos[currEgg].first+=eggInfos[i].second;
    }

    if(!hit) ret=getMaxBreak(eggInfos, currEgg+1);

    return ret;
}

int main() {
    cin>>eggNum;
    vector<pair<int, int>> eggInfos(eggNum);

    for(int i=0; i<eggNum; i++) {
        cin>>eggInfos[i].first>>eggInfos[i].second;
    }

    cout<<getMaxBreak(eggInfos, 0);
}