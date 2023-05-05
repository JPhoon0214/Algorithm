최솟값
====
<br/>

>### 문제 유형/난이도
>골드1 / 세그먼트 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/10868">문제 바로 가기(baekjoon 10868)</a>
<br/>

>### 코드
```C++
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
```
<br/>

>### 회고
>역시 이번에도 1트에 성공하지 못했다...이번엔 다른 이유가 아니라 입력이 `int` 범위 안에 있을 때 습관적으로 최대값을 `987654321`로 잡는데, 입력될 수 있는 값이 10억 이하의 자연수였다. 그래도 이번엔 한번 당한 적이 있어서 그런지 금방 수정해 풀긴 했지만 다음에 또 틀리면 곤란하다. 입력 범위를 항상 꼼꼼히 살펴야겠다.