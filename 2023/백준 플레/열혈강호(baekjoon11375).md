열혈강호
====
<br/>

>### 문제 유형/난이도
>플레4 / 이분 매칭
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/11375">문제 바로 가기(baekjoon 11375)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int index, vector<vector<int>>& availWorks, vector<int>& matching, vector<bool>& visited) {
    for(int i=0; i<availWorks[index].size(); i++) {
        int workIndex=availWorks[index][i];

        if(visited[workIndex]) {
            continue;
        }
        visited[workIndex]=true;

        if(matching[workIndex]==-1 || dfs(matching[workIndex], availWorks, matching, visited)) {
            matching[workIndex]=index;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int workerNum, workNum;
    cin>>workerNum>>workNum;

    vector<vector<int>> availWorks(workerNum);

    for(int i=0; i<workerNum; i++) {
        int availWorkNum;
        cin>>availWorkNum;
        availWorks[i]=vector<int>(availWorkNum);
        for(int j=0; j<availWorkNum; j++) {
            cin>>availWorks[i][j];
        }
    }

    vector<int> matching(workNum+1, -1);

    int cnt=0;
    for(int i=0; i<workerNum; i++) {
        vector<bool> visited(workNum+1, false);

        if(dfs(i, availWorks, matching, visited)) {
            cnt++;
        }
    }
    cout<<cnt;
}
```
<br/>

>### 회고
> 이분 매칭을 공부하면서 풀어본 문제이다. 다만 다른 이분 매칭 문제들과 풀이법이 크게 다르지도 않고, 문제를 봤을 때 이분 매칭 문제인지 알아차리는 것도 어려워 보이지 않았다. 남은 이분 매칭 문제들은 시간을 두고 조금 잊어버릴