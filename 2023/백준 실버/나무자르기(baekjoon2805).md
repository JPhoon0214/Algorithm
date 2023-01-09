나무자르기
====
<br/>

>### 문제 유형/난이도
>실버2 / 이분 탐색
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2805">문제 바로 가기(baekjoon 2805)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

long long cutTrees(int standard, vector<int>& trees) {
    long long ret=0;
    for(int i=0; i<trees.size(); i++) {
        if(standard<trees[i]) {
            ret+=(trees[i]-standard);
        }
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int treeNum, target;
    cin>>treeNum>>target;
    vector<int> trees(treeNum);
    int maxHeight=0;
    
    for(int i=0; i<treeNum; i++) {
        cin>>trees[i];
        maxHeight=max(maxHeight, trees[i]);
    }

    int left=0;
    int right=maxHeight;
    while(left+1<right) {
        int mid=(left+right)/2;
        long long getWood=cutTrees(mid, trees);
        if(getWood>target) {
            left=mid;
        }
        else {
            right=mid;
        }
    }
    int ret=left;
    if(cutTrees(right, trees)>=target)
        ret=right;
    if(cutTrees)
    cout<<ret;
}
```
<br/>

>### 회고
>수의 범위가 1~20억으로 O(n)의 알고리즘으로는 풀 수 없었다.
>자연스럽게 이진 검색을 이용해 푸는 아이디어를 떠올릴 수 있었다.
>최종 시간 복잡도는 nlogn으로 복잡한 구현 없이 시간 안에 푸는 것이 가능했다.<br/>
    
>실버2 문제였지만, 2번 틀린 후에 정답을 받을 수 있었다.
>생각보다 이진 검색 알고리즘을 짜는데 애를 먹었는데, 이진 검색 트리에 대해 공부를 더 해야 할 것 같다