수열과 쿼리16
====
<br/>

>### 문제 유형/난이도
>골드1 / 세그먼트 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14428">문제 바로 가기(baekjoon 14428)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int init(int start, int end, int node, vector<int>& inputs, vector<int>& segTree) {
    if(start==end) return segTree[node]=start;

    int mid=(start+end)/2;
    
    int leftIndex=init(start, mid, node*2, inputs, segTree);
    int rightIndex=init(mid+1, end, node*2+1, inputs, segTree);

    if(inputs[leftIndex]<inputs[rightIndex]) {
        return segTree[node]=leftIndex;
    }
    else if(inputs[leftIndex]>inputs[rightIndex]) {
        return segTree[node]=rightIndex;
    }
    else {
        return segTree[node]=min(leftIndex, rightIndex);
    }
}

int changeNode(int start, int end, int node, int changeIndex, vector<int>& segTree, vector<int>& inputs) {
    if(start>changeIndex || end<changeIndex) return segTree[node];
    if(start==end) return segTree[node];

    int mid=(start+end)/2;
    int indexLeft=changeNode(start, mid, node*2, changeIndex, segTree, inputs);
    int indexRight=changeNode(mid+1, end, node*2+1, changeIndex, segTree, inputs);
    
    if(inputs[indexLeft]>inputs[indexRight]) {
        return segTree[node]=indexRight;
    }
    else if(inputs[indexLeft]<inputs[indexRight]) {
        return segTree[node]=indexLeft;
    }
    else {
        return segTree[node]=min(indexLeft, indexRight);
    }
    
}

int getAnsIndex(int start, int end, int node, int rangeLow, int rangeHigh, vector<int>& segTree, vector<int>& inputs) {
    if(rangeLow>end || rangeHigh<start) return -1;
    if(rangeLow<=start && rangeHigh>=end) return segTree[node];

    int mid=(start+end)/2;

    int left=getAnsIndex(start, mid, node*2, rangeLow, rangeHigh, segTree, inputs);
    int right=getAnsIndex(mid+1, end, node*2+1, rangeLow, rangeHigh, segTree, inputs);

    if(left!=-1 && right!=-1) {
        if(inputs[left]<inputs[right]) {
            return left;
        }
        else if(inputs[left]>inputs[right]) {
            return right;
        }
        else {
            return min(left, right);
        }
    }
    else {
        if(left==-1 && right==-1) {
            return -1;
        }
        else {
            return max(left, right);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nodeNum;
    cin>>nodeNum;
    
    vector<int> inputs(nodeNum);
    for(int i=0; i<nodeNum; i++) cin>>inputs[i];

    vector<int> segTree(300000, -1);

    init(0, nodeNum-1, 1, inputs, segTree);

    int calNum;
    cin>>calNum;

    for(int i=0; i<calNum; i++) {
        int flag, num1, num2;
        cin>>flag>>num1>>num2;

        if(flag==1) {
            inputs[num1-1]=num2;
            changeNode(0, nodeNum-1, 1, num1-1, segTree, inputs);
        }
        else {
            cout<<getAnsIndex(0, nodeNum-1, 1, num1-1, num2-1, segTree, inputs)+1<<"\n";
        }
    }
}
```
<br/>

>### 회고
>세그먼트 트리 역시 맛있다... 그런데 한번에 정답 처리를 받기가 어려운 거 같다.
>아직 조금 생각이 깊게 안되는거 같기두... 문제 풀이 수가 부족한가보다.