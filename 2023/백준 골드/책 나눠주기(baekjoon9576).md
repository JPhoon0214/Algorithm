책 나눠주기
====
<br/>

>### 문제 유형/난이도
>골드2 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/9576">문제 바로 가기(baekjoon 9576)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int index, vector<int>& owner, vector<pair<int, int>>& infos, vector<bool>& visited) {
    for(int i=infos[index].first; i<=infos[index].second; i++) {
        if(visited[i])
            continue;
        visited[i]=true;
        if(owner[i]==-1 || dfs(owner[i], owner, infos, visited)) {
            owner[i]=index;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin>>testCase;
    for(testCase; testCase>0; testCase--) {
        int bookNum, stdNum;
        cin>>bookNum>>stdNum;
        vector<pair<int, int>> infos(stdNum); //infos[i]: i번째 학생의 원하는 책 범위
        for(int i=0; i<stdNum; i++) {
            cin>>infos[i].first>>infos[i].second;
        }

        // owner[i]: i번 책의 주인의 번호
        vector<int> owner(bookNum+1, -1);

        int cnt=0;
        for(int i=0; i<stdNum; i++) {
            // visited[i]: i번째 책이 누군가에게 배정됐는가? 새로운 매칭 시도를 할 때마다 초기화 되므로, 배정된 적이 있는 책은 고려하지 않음
            vector<bool> visited(bookNum+1, false);
            if(dfs(i, owner, infos, visited)) {
                cnt+=1;
            }
        }
        cout<<cnt<<"\n";
    }
}
```
<br/>

>### 회고
>이분 매칭 알고리즘을 공부해 볼 겸 풀어본 문제다. 아직 이분 매칭이 익숙하진 않은데, 비슷한 문제를 더 풀어보면서 익숙해져 봐야겠다.