커피숍2
====
<br/>

>### 문제 유형/난이도
>골드1 / 세그먼트 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1275">문제 바로 가기(baekjoon 1275)</a>
<br/>

>### 코드
```C++
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

long long find(int start, int end, int node, int rangeLow, int rangeHigh, vector<long long>& segTree) {
    if(rangeHigh<start || rangeLow>end) return 0;
    if(start>=rangeLow && end<=rangeHigh) return segTree[node];

    int mid=(start+end)/2;

    return find(start, mid, node*2, rangeLow, rangeHigh, segTree)+find(mid+1, end, node*2+1, rangeLow, rangeHigh, segTree);
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

    vector<long long> inputs(nodeNum);
    for(int i=0; i<nodeNum; i++) {
        cin>>inputs[i];
    }

    vector<long long> segTree(400000, -1);

    init(0, nodeNum-1, 1, inputs, segTree);

    for(int i=0; i<calNum; i++) {
        int rangeLow, rangeHigh;
        cin>>rangeLow>>rangeHigh;

        if(rangeLow>rangeHigh) {
            swap(rangeLow, rangeHigh);
        }

        int targetIndex, changeTo;
        cin>>targetIndex>>changeTo;

        cout<<find(0, nodeNum-1, 1, rangeLow-1, rangeHigh-1, segTree)<<"\n";
        change(0, nodeNum-1, 1, targetIndex-1, changeTo, segTree);
    }
}
```
<br/>

>### 회고
>또 한번 틀렸다...이번엔 좀 억울한게 문제가 이상하다...! x~y까지의 구간 합을 구하는 문제였는데 알고보니 x가 y보다 클 수도 있었다. 밑에 노트에 적혀 있었으니 문제를 잘 보지 않은 내 잘못이다...이정도면 세그먼트 트리는 한번에 풀지 못하도록 세상이 억까하는게 아닐까.