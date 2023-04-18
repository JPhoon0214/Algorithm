개미
====
<br/>

>### 문제 유형/난이도
>플레5 / DFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14942">문제 바로 가기(baekjoon 14942)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int>& nextVertex, vector<int>& nextCost, vector<vector<int>>& linked, vector<vector<int>>& costs, vector<bool>& visited) {
    visited[v]=true;
    
    for(int i=0; i<linked[v].size(); i++) {
        int nextV=linked[v][i];
        if(visited[nextV]) continue;

        nextVertex[nextV]=v;
        nextCost[nextV]=costs[v][i];

        dfs(nextV, nextVertex, nextCost, linked, costs, visited);
    }
}

int main() {
    int n;
    cin>>n;

    vector<pair<int, int>> antInfo(n);
    for(int i=0; i<n; i++) {
        cin>>antInfo[i].first;
        antInfo[i].second=i+1;
    }

    vector<vector<int>> linked(n+1);
    vector<vector<int>> costs(n+1);
    for(int i=0; i<n-1; i++) {
        int v1, v2, cost;
        cin>>v1>>v2>>cost;
        
        linked[v1].push_back(v2);
        linked[v2].push_back(v1);

        costs[v1].push_back(cost);
        costs[v2].push_back(cost);
    }

    vector<bool> visited(n+1, false);
    vector<int> nextVertex(n+1);
    vector<int> nextCost(n+1);

    dfs(1, nextVertex, nextCost, linked, costs, visited);

    for(int i=0; i<antInfo.size(); i++) {
        int currPower=antInfo[i].first;
        int currV=antInfo[i].second;
        
        
        while(currPower>=nextCost[currV] && currV!=1) {
            currPower-=nextCost[currV];
            currV=nextVertex[currV];
        }

        cout<<currV<<"\n";
    }
}
```
<br/>

>### 회고
>플레 문제 치고는 그래도 어떻게 풀지 감을 잡기는 쉬었다.
>약간 별 생각 없이 뚝딱뚝딱 풀다 보니 된 것 같다.
>하지만 내가 푼 방법이 가장 간단한 방법인지는 잘 모르겠다.
>다른 사람의 풀이와 비교해 보며 공부해야겠다.