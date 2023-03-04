#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getFlowerNum(int startDay, int endDay, vector<pair<int, int>>& infos, int infoIndex) {
    if(infoIndex>=infos.size() || infos[infoIndex].first>startDay) {
        return -987654321;
    }
    
    int lastDay=-1;
    
    for(; infoIndex<infos.size()&&infos[infoIndex].first<=startDay; infoIndex++) {
        lastDay=max(lastDay, infos[infoIndex].second);
    }

    if(lastDay>endDay) {
        return 1;
    }
    else {
        return getFlowerNum(lastDay, endDay, infos, infoIndex)+1;
    }
}

int main() {
    vector<int> monthToDay(12, 0);
    for(int i=1; i<12; i++) {
        monthToDay[i]=monthToDay[i-1]+month[i-1];
    }

    int n;
    cin>>n;

    vector<pair<int, int>> infos(n);

    for(int i=0; i<n; i++) {
        int sMonth, sDay;
        int eMonth, eDay;

        cin>>sMonth>>sDay>>eMonth>>eDay;

        infos[i]=pair<int, int>({monthToDay[sMonth-1]+sDay, monthToDay[eMonth-1]+eDay});
    }
    
    sort(infos.begin(), infos.end());

    int startDay=monthToDay[2]+1;
    int endDay=monthToDay[10]+30;

    int ret=getFlowerNum(startDay, endDay, infos, 0);

    if(ret<=0) {
        cout<<0;
    }
    else {
        cout<<ret;
    }
}