회사문화

>### 문제 유형/난이도
>골드4 / DFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14267">문제 바로 가기(baekjoon 14267)</a>

<br/>

>### 코드
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getRet(vector<int>& getScore, vector<vector<int> >& relation, int currIndex, int currScore) {
    getScore[currIndex]+=currScore;

    for(int i=0; i<relation[currIndex].size(); i++) {
        int nextIndex=relation[currIndex][i];
        getRet(getScore, relation, nextIndex, getScore[currIndex]);
    }
} 

int main() {
    int workerNum, inputNum;
    cin>>workerNum>>inputNum;

    vector<vector<int> > relation(workerNum);

    for(int i=0; i<workerNum; i++) {
        int parent;
        cin>>parent;

        if(parent==-1) continue;

        relation[parent-1].push_back(i);
    }

    vector<int> getScore(workerNum, 0);
    for(int i=0; i<inputNum; i++) {
        int workerIndex, score;
        cin>>workerIndex>>score;
        getScore[workerIndex-1]+=score;
    }

    getRet(getScore, relation, 0, 0);

    for(int i=0; i<workerNum; i++) {
        cout<<getScore[i]<<" ";
    }
}
```
<br/>

>### 회고
어제 새로운 친구를 사귀어서 밤새 술먹고 노느라 문제를 못 풀었다...오늘도 고등학교 친구들을 보기로 했는데 아마 다녀와서 못 풀거 같아서 빠르게 간단한 문제를 한 문제 풀었다.  
조금 문제 설명이 부족한 거 아닌가 싶긴 한데 아마 직속 상사는 한명이고 부하직원은 여러명이며 사장을 제외하고 직속상사가 없는 직원은 없을 것이라 생각하고 풀었다. DP로도 풀 수 있다고 하는데, 어차피 DP를 써도 그래프를 이용해야 할 것 같기도 하고, 위와 같이 변수로 지금까지 칭찬 받은 값을 부하 직원 노드에 넘겨주면 쉽게 풀리기 때문에 굳이 DP를 이용하진 않았다. 아니 그래도 getScore에 저장을 한 것을 이용해 풀었으니 DP를 썼다고 해야 하나...? 부하 직원이 직속상사보다 인덱스가 크다는 조건이 있었기 때문에 코드에 따라 탐색하면서 바로바로 출력해도 인덱스 순서대로 답이 나왔을 거 같기도 한데 이렇게 푸는게 생각도 덜 해도 되고 틀릴 위험도 적다 생각해 단순하게 풀었다.  