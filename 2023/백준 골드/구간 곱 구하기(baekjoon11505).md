구간 곱 구하기
====
<br/>

>### 문제 유형/난이도
>골드1 / 세그먼트 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/11505">문제 바로 가기(baekjoon 11505)</a>
<br/>

>### 코드
```C++
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
```
<br/>

>### 회고
>> 3일동안 못풀었다. 업데이트 하는 방식을 어떻게 할 지 고민하면서 이것 저것 해 봤는데 다른 방법으로 구현하려 하면 생각보다 어렵다. 몇번의 오답과 시간 초과를 낸 이후 풀 수 있었다. 한동안 백준 솔브 로그를 못 남겼는데 공부를 안한게 아니라 그냥 못 푼거다...