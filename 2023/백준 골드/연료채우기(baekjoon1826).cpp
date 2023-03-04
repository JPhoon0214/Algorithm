#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int, int>> infos(n);
    for(int i=0; i<n; i++) {
        cin>>infos[i].first>>infos[i].second;
    }
    sort(infos.begin(), infos.end());

    int target, currFuel;
    cin>>target>>currFuel;

    int infoIndex=0;
    priority_queue<int> pq;

    int cnt=0;

    while(currFuel<target) {
        while(infoIndex<infos.size() && currFuel>=infos[infoIndex].first) {
            pq.push(infos[infoIndex].second);
            infoIndex++;
        }
        
        if(pq.empty()) {
            break;
        }
        
        currFuel+=pq.top();
        pq.pop();
        cnt++;
    }

    if(currFuel<target) {
        cout<<-1;
    }
    else {
        cout<<cnt;        
    }
}