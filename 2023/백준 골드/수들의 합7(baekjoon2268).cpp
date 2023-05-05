#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long init(int start, int end, int node, vector<long long>& inputs, vector<long long>& segTree) {
    if(start==end) {
        return segTree[node]=inputs[start];
    }

    int mid=(start+end)/2;
    
    return segTree[node]=init(start, mid, node*2, inputs, segTree)+init(mid+1, end, node*2+1, inputs, segTree);
}

long long sumSeg(int start, int end, int node, int rangeLow, int rangeHigh, vector<long long>& segTree) {
    if(rangeHigh<start || rangeLow>end) return 0;
    if(start>=rangeLow && end<=rangeHigh) return segTree[node];

    int mid=(start+end)/2;

    return sumSeg(start, mid, node*2, rangeLow, rangeHigh, segTree)+sumSeg(mid+1, end, node*2+1, rangeLow, rangeHigh, segTree);
}

long long change(int start, int end, int node, int targetIndex, long long changeTo, vector<long long>& segTree) {
    if(start>targetIndex || end<targetIndex) return segTree[node];
    if(start==end) return segTree[node]=changeTo;

    int mid=(start+end)/2;

    return segTree[node]=change(start, mid, node*2, targetIndex, changeTo, segTree)+change(mid+1, end, node*2+1, targetIndex, changeTo, segTree);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nodeNum, calNum;
    cin>>nodeNum>>calNum;

    vector<long long> inputs(nodeNum, 0);

    vector<long long> segTree(4000000, -1);

    init(0, nodeNum-1, 1, inputs, segTree);

    for(int i=0; i<calNum; i++) {
        int flag, num1, num2;
        cin>>flag>>num1>>num2;

        if(flag==0) {
            if(num1>num2) {
                swap(num1, num2);
            }
    
            cout<<sumSeg(0, nodeNum-1, 1, num1-1, num2-1, segTree)<<"\n";
            
        }
        else {
            change(0, nodeNum-1, 1, num1-1, num2, segTree);
        }
    }
}