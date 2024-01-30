#include <iostream>
#include <vector>

using namespace std;

int totalMax=0;

int getSideLen(vector<vector<pair<int, int> > >& connection, int parent) {
    int currMaxLen=0;
    int currSecondMaxLen=0;

    for(int i=0; i<connection[parent].size(); i++) {
        int child=connection[parent][i].first;
        int weight=connection[parent][i].second;
        int ret=getSideLen(connection, child)+weight;

        if(currMaxLen<ret) {
            currSecondMaxLen=currMaxLen;
            currMaxLen=ret;
        }
        else if(currSecondMaxLen<ret) {
            currSecondMaxLen=ret;
        }
    }

    totalMax=max(totalMax, currMaxLen+currSecondMaxLen);
    return currMaxLen;
}

int main() {
    int n;
    cin>>n;

    vector<bool> isRoot(n, true);

    vector<vector<pair<int, int> > > connection(n, vector<pair<int, int> >());
    for(int i=0; i<n-1; i++) {
        int parent, child, weight;
        cin>>parent>>child>>weight;
        connection[parent-1].push_back({child-1, weight});
        isRoot[child-1]=false;
    }

    int root=-1;
    for(int i=0; i<n; i++) {
        if(isRoot[i]) {
            root=i;
            break;
        }
    }

    getSideLen(connection, root);
    cout<<totalMax;
}