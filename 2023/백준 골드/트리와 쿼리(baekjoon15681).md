트리와 쿼리
====
<br/>

>### 문제 유형/난이도
>골드5 / DP, 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/15681">문제 바로 가기(baekjoon 15681)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<int> cache(100000, -1);
int n, root, q;

int search(vector<vector<int>>& connect, int root, vector<bool>& visited) {
    if(visited[root])
        return -1;
    visited[root]=true;
    int& ret=cache[root];
    if(ret!=-1)
        return ret;
    
    ret=0;
    for(int i=0; i<connect[root].size(); i++) {
        ret+=(search(connect, connect[root][i], visited)+1);
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>root>>q;
    vector<vector<int>> connect(n);
    vector<bool> visited(n, false);

    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin>>v1>>v2;
        connect[v1-1].push_back(v2-1);
        connect[v2-1].push_back(v1-1);
    }
    search(connect, root-1, visited);

    for(int i=0; i<q; i++) {
        int index;
        cin>>index;
        cout<<cache[index-1]+1<<"\n";
    }
}
```
<br/>

>### 회고
>DP를 적용하는 것은 어렵지 않지만, 트리를 만들 때 조금 주의해야 하는 문제였다. 이 문제에서는 굳이 구조체를 이용해 트리를 구현할 필요 없이 배열을 이용해 유사 트리를 만들어 푸는 것이 일반적인 선택일텐데, 그렇다면 n*n크기의 bool 배열을 만들어 각 정점이 어느 정점과 연결되어 있고 연결되어 있지 않은지 저장할 수도 있고, 또는 n크기의 동적 배열을 만들어 각 정점마다 연결된 정점이 있을 경우 동적 배열에 해당 정점을 push 해주는 방식으로 구현할 수도 있다. 이 문제를 첫번째 방법으로 구현할 경우 최대 10^10크기의 배열을 만들어야 하기 때문에 메모리 초과가 발생할 수 있다. 반면 두번째 방법으로 구현할 경우 약 2 * 10^5개 정도의 배열만 만들어도 충분하기 때문에 쉽게 문제를 풀 수 있다. 