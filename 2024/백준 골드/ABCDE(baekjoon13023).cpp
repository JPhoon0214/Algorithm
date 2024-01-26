#include <iostream>
#include <vector>

using namespace std;

int getDepth(vector<vector<int> >& frineds, vector<bool>& visited, int index, int depth) {
    if(visited[index]) return 0;
    if(depth>4) return 1;

    visited[index]=true;
    int ret=1;
    for(int i=0; i<frineds[index].size(); i++) {
        ret=max(ret, getDepth(frineds, visited, frineds[index][i], depth+1)+1);
        if(ret>4) break;
    }
    visited[index]=false;
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int pNum, relationNum;
    cin>>pNum>>relationNum;

    vector<vector<int> > friends(pNum, vector<int>());
    vector<bool> visited(pNum, false);

    for(int i=0; i<relationNum; i++) {
        int p1, p2;
        cin>>p1>>p2;
        friends[p1].push_back(p2);
        friends[p2].push_back(p1);
    }

    bool isAvail=false;

    for(int i=0; i<pNum; i++) {
        if(getDepth(friends, visited, i, 1)>4) {
            isAvail=true;
            break;
        }
    }

    if(isAvail) cout<<1;
    else cout<<0;
}