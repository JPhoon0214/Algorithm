#include <iostream>
#include <vector>

using namespace std;

int init(int start, int end, int node, vector<int>& inputs, vector<int>& segTree) {
    if(start==end) {
        return segTree[node]=inputs[start];
    }

    int mid=(start+end)/2;
    
    return segTree[node]=min(init(start, mid, node*2, inputs, segTree), init(mid+1, end, node*2+1, inputs, segTree));
}

int find(int start, int end, int node, int rangeLow, int rangeHigh, vector<int>& segTree) {
    if(rangeHigh<start || rangeLow>end) return 1987654321;
    if(start>=rangeLow && end<=rangeHigh) return segTree[node];

    int mid=(start+end)/2;

    return min(find(start, mid, node*2, rangeLow, rangeHigh, segTree), find(mid+1, end, node*2+1, rangeLow, rangeHigh, segTree));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nodeNum, calNum;
    cin>>nodeNum>>calNum;

    vector<int> inputs(nodeNum);
    for(int i=0; i<nodeNum; i++) {
        cin>>inputs[i];
    }

    vector<int> segTree(400000, -1);

    init(0, nodeNum-1, 1, inputs, segTree);

    for(int i=0; i<calNum; i++) {
        int rangeLow, rangeHigh;
        cin>>rangeLow>>rangeHigh;

        cout<<find(0, nodeNum-1, 1, rangeLow-1, rangeHigh-1, segTree)<<"\n";
    }
}