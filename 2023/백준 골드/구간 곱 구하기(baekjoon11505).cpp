#include <iostream>
#include <vector>

using namespace std;

const int DIVIDER=1000000007;

long long initSeg(int start, int end, int node, vector<int>& inputs, vector<long long>& segTree) {
    if(start==end) {
        return segTree[node]=inputs[start];
    }

    int mid=(start+end)/2;
    return segTree[node]=(initSeg(start, mid, node*2, inputs, segTree)*initSeg(mid+1, end, node*2+1, inputs, segTree))%DIVIDER;
}

long long changeSeg(int start, int end, int node, int pos, int toChange, vector<long long>& segTree) {
    if(pos<start || pos>end) return segTree[node];

    if(start==end) return segTree[node]=toChange;

    int mid=(start+end)/2;
    
    return segTree[node]=(changeSeg(start, mid, node*2, pos, toChange, segTree)*changeSeg(mid+1, end, node*2+1, pos, toChange, segTree))%DIVIDER;
}

long long getAns(int start, int end, int node, int rangeLeft, int rangeRight, vector<long long>& segTree) {
    if(rangeLeft>end || rangeRight<start) return 1;
    if(start>=rangeLeft && end<=rangeRight) {
        return segTree[node];
    }

    int mid=(start+end)/2;
    return (getAns(start, mid, node*2, rangeLeft, rangeRight, segTree)*getAns(mid+1, end, node*2+1, rangeLeft, rangeRight, segTree))%DIVIDER;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nodeNum, changeNum, calNum;
    cin>>nodeNum>>changeNum>>calNum;

    vector<int> inputs(nodeNum);
    for(int i=0; i<nodeNum; i++) cin>>inputs[i];

    vector<long long> segTree(3000000, 0);

    initSeg(0, nodeNum-1, 1, inputs, segTree);
    
    for(int i=0; i<changeNum+calNum; i++) {
        int flag, num1, num2;
        cin>>flag>>num1>>num2;

        if(flag==1) {
            changeSeg(0, nodeNum-1, 1, num1-1, num2, segTree);
            inputs[num1-1]=num2;
        }
        else {
            cout<<getAns(0, nodeNum-1, 1, num1-1, num2-1, segTree)<<"\n";
        }
    }
}