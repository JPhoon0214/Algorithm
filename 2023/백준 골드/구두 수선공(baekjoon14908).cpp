#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int time;
    int cost;
    int index;
    bool operator<(Info& next);
};
bool Info::operator<(Info& next) {
    if(cost*next.time<next.cost*time) {
        return true;        
    }
    else if(cost*next.time>next.cost*time) {
        return false;        
    }
    else {
        return index>next.index;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int taskNum;
    cin>>taskNum;
    vector<Info> infos(taskNum);
    for(int i=0; i<taskNum; i++) {
        cin>>infos[i].time>>infos[i].cost;
        infos[i].index=i+1;
    }
    sort(infos.begin(), infos.end());
    for(int i=taskNum-1; i>=0; i--) {
        cout<<infos[i].index<<" ";
    }
}