#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nodeNum, changeNum, calNum;

long long setNodes(int start, int end, int target, vector<long long>& segTree, vector<long long>& inputs) {
    if(start==end) return segTree[target]=inputs[start];

    int mid=(start+end)/2;

    segTree[target]=setNodes(start, mid, target*2, segTree, inputs)+setNodes(mid+1, end, target*2+1, segTree, inputs);
    return segTree[target];
}

void changeNode(int pos, long long dif, vector<long long>& segTree, int start, int end, int target) {
    if(pos<start || pos>end) return;
    
    if(start==end) {
        segTree[target]+=dif;
        return;
    }

    segTree[target]+=dif;

    int mid=(start+end)/2;
    
    changeNode(pos, dif, segTree, start, mid, target*2);
    changeNode(pos, dif, segTree, mid+1, end, target*2+1);
}

long long sumNum(int start, int end, vector<long long>& segTree, int target, int rangeLow, int rangeHigh) {
    if(start>=rangeLow && end<=rangeHigh) return segTree[target];
    else if(start>rangeHigh || end<rangeLow) return 0;

    int mid=(start+end)/2;

    return sumNum(start, mid, segTree, target*2, rangeLow, rangeHigh)+sumNum(mid+1, end, segTree, target*2+1, rangeLow, rangeHigh);    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>nodeNum>>changeNum>>calNum;
    
    vector<long long> segTree(3000000, 0);

    vector<long long> inputs(nodeNum);
    for(int i=0; i<nodeNum; i++) {
        cin>>inputs[i];
    }

    setNodes(0, nodeNum-1, 1, segTree, inputs);

    for(int i=0; i<changeNum+calNum; i++) {
        long long flag, num1, num2;
        cin>>flag>>num1>>num2;

        if(flag==1) {
            changeNode(num1-1, num2-inputs[num1-1], segTree, 0, nodeNum-1, 1);
            inputs[num1-1]=num2;
        }
        else {
            cout<<sumNum(0, nodeNum-1, segTree, 1, num1-1, num2-1)<<"\n";
        }
    }
}