구간 합 구하기
====
<br/>

>### 문제 유형/난이도
>골드1 / 세그먼트 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2042">문제 바로 가기(baekjoon 2042)</a>
<br/>

>### 코드
```C++
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
```
<br/>

>### 회고
>>처음으로 풀어본 세그먼트 트리 문제이다. 솔브드에이씨 클래스를 따고 싶어서 세그먼트 트리를 조금 공부해 봤다. 조금 신선하고 신기했다. 세그먼트 트리 문제를 조금 더 풀어본 후 블로그에 정리해야겠다.