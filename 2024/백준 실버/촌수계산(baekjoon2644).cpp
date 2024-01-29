#include <iostream>
#include <vector>

using namespace std;

int MAXNUM=987654321;

int n;

int getDis(int curr, int target, vector<vector<bool> >& pairs, vector<bool>& visited) {
    if(visited[curr]) return MAXNUM;
    if(curr==target) return 0;

    visited[curr]=true;

    int ret=MAXNUM;

    for(int i=0; i<n; i++) {
        if(!pairs[curr][i]) continue;

        int next=i;
        ret=min(ret, getDis(next, target, pairs, visited)+1);
    }

    visited[curr]=false;

    return ret;
}

int main() {
    cin>>n;
    int target1, target2;
    cin>>target1>>target2;

    int relationNum;
    cin>>relationNum;

    vector<vector<bool> > pairs(n, vector<bool>(n, false));

    for(int i=0; i<relationNum; i++) {
        int index1, index2;
        cin>>index1>>index2;
        pairs[index1-1][index2-1]=true;
        pairs[index2-1][index1-1]=true;
    }

    vector<bool> visited(n, false);

    int ret=getDis(target1-1, target2-1, pairs, visited);
    if(ret>=MAXNUM) cout<<-1;
    else cout<<ret;
}