축사배정
====
<br/>

>### 문제 유형/난이도
>플레4 / 이분 매칭
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2188">문제 바로 가기(baekjoon 2188)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int index, vector<vector<int>>& wishHouse, vector<bool>& visited, vector<int>& owner) {
    for(int i=0; i<wishHouse[index].size(); i++) {
        int houseIndex=wishHouse[index][i];
        if(visited[houseIndex]) {
            continue;
        }
        visited[houseIndex]=true;
        if(owner[houseIndex]==-1 || dfs(owner[houseIndex], wishHouse, visited, owner)) {
            owner[houseIndex]=index;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cowNum, houseNum;
    cin>>cowNum>>houseNum;

    //wishHouse[i]: i번째 소가 들어가고 싶어하는 축사 그룹
    vector<vector<int>> wishHouse(cowNum);
    for(int i=0; i<cowNum; i++) {
        int wishNum;
        cin>>wishNum;
        wishHouse[i]=vector<int>(wishNum);
        for(int j=0; j<wishNum; j++) {
            cin>>wishHouse[i][j];
        }
    }

    //owner[i]: i번째 축사에 들어간 소의 번호
    vector<int> owner(houseNum+1, -1);
    
    int cnt=0;
    for(int i=0; i<cowNum; i++) {
        //visited[i]: i번째 축사가 배정된 적이 있는가
        vector<bool> visited(houseNum+1, false);

        if(dfs(i, wishHouse, visited, owner)) {
            cnt+=1;
        }
    }
    cout<<cnt;
}
```
<br/>

>### 회고
>이분 매칭을 공부하기 위해 푼 두번째 문제다. 이분 매칭을 알고 있으면 쉽게 풀리는 문제인데, 개념의 난이도 때문에 플레 문제가 된건가...?싶다. 이분 매칭에 조금 더 익숙해 지자는 생각으로 풀어본 문제이지만, 조금 생각을 덜 하고 문제를 푼 것 같다. 풀이 방법이 손에 익었으니 조금 더 개념을 천천히 정리해 보는 시간이 필요할 것 같다.