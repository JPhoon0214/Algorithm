#include <iostream>
#include <vector>

using namespace std;

int nodeNum, rangeNum;

const int FLAGINF[2]={-1999999999, 1999999999};

int setTree(int start, int end, vector<int>& inputs, vector<int>& segTree, int target, int flag) {
    if(start==end) return segTree[target]=inputs[start];

    int mid=(start+end)/2;

    if(flag==1) {
        return segTree[target]=max(setTree(start, mid, inputs, segTree, target*2, flag), setTree(mid+1, end, inputs, segTree, target*2+1, flag));
    }
    else {
        return segTree[target]=min(setTree(start, mid, inputs, segTree, target*2, flag), setTree(mid+1, end, inputs, segTree, target*2+1, flag));
    }
}

int findAns(int start, int end, int target, vector<int>& segTree, int flag, int rangeLow, int rangeHigh) {
    if(start>=rangeLow && end<=rangeHigh) return segTree[target];

    if(start>rangeHigh || end<rangeLow) return FLAGINF[flag];

    int mid=(start+end)/2;

    if(flag==0) {
        return max(findAns(start, mid, target*2, segTree, flag, rangeLow, rangeHigh), findAns(mid+1, end, target*2+1, segTree, flag, rangeLow, rangeHigh));
    }
    else {
        return min(findAns(start, mid, target*2, segTree, flag, rangeLow, rangeHigh), findAns(mid+1, end, target*2+1, segTree, flag, rangeLow, rangeHigh));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>nodeNum>>rangeNum;

    vector<int> inputs(nodeNum);
    for(int i=0; i<nodeNum; i++) {
        cin>>inputs[i];
    }

    vector<int> maxSegTree(300000, 0);
    vector<int> minSegTree(300000, 0);

    setTree(0, nodeNum-1, inputs, maxSegTree, 1, 1);
    setTree(0, nodeNum-1, inputs, minSegTree, 1, 2);

    for(int i=0; i<rangeNum; i++) {
        int start, end;
        cin>>start>>end;

        cout<<findAns(0, nodeNum-1, 1, minSegTree, 1, start-1, end-1)<<" ";
        cout<<findAns(0, nodeNum-1, 1, maxSegTree, 0, start-1, end-1)<<"\n";
    }    
}