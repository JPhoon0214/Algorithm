카드게임
====

>### 문제 유형/난이도
>골드4 / DFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1967">문제 바로 가기(baekjoon 1967)</a>

<br/>

>### 코드
```c++
#include <iostream>
#include <vector>

using namespace std;

int totalMax=0;

int getSideLen(vector<vector<pair<int, int> > >& connection, int parent) {
    int currMaxLen=0;
    int currSecondMaxLen=0;

    for(int i=0; i<connection[parent].size(); i++) {
        int child=connection[parent][i].first;
        int weight=connection[parent][i].second;
        int ret=getSideLen(connection, child)+weight;

        if(currMaxLen<ret) {
            currSecondMaxLen=currMaxLen;
            currMaxLen=ret;
        }
        else if(currSecondMaxLen<ret) {
            currSecondMaxLen=ret;
        }
    }

    totalMax=max(totalMax, currMaxLen+currSecondMaxLen);
    return currMaxLen;
}

int main() {
    int n;
    cin>>n;

    vector<bool> isRoot(n, true);

    vector<vector<pair<int, int> > > connection(n, vector<pair<int, int> >());
    for(int i=0; i<n-1; i++) {
        int parent, child, weight;
        cin>>parent>>child>>weight;
        connection[parent-1].push_back({child-1, weight});
        isRoot[child-1]=false;
    }

    int root=-1;
    for(int i=0; i<n; i++) {
        if(isRoot[i]) {
            root=i;
            break;
        }
    }

    getSideLen(connection, root);
    cout<<totalMax;
}
```
<br/>

>### 회고
매일 알고리즘을 풀고 있긴 한데 정리는 오랜만에 하는 것 같다.  
내일 알고리즘 스터디가 있는데, 나에게 할당된 문제는 이 문제다. 평범한 그래프가 아닌 트리 구조이기 때문에 양방향 그래프가 아닌 단반향 그래프로 생각해 부모 노드에서 자식 노드로 탐색을 하도록 강제했다. 물론 이렇게 하려면 가장 윗단의 루트 노트를 찾아야 한다. 또한 이 문제에서는 숫자가 작은 노드가 부모 노드가 아닐 수 있으며 이진 트리가 아닐 수 있다는 점도 생각해야 한다. 예시가 전부 위 상황밖에 없어서 무심결에 놓치기 쉬웠다.  
모든 부모 노드를 돌면서 그 부모 노드를 루트로 하는 서브 트리에서 만들어 질 수 있는 최대 지름을 구해 전역 변수에 계속 저장했고, 동시에 그래프를 탐색하는 함수는 해당 노드부터 한 방향으로 내려갈 때 얻을 수 있는 최대 길이를 반환하도록 했다. 트리는 자식 노드가 부모 노드를 하나만 가지기 때문에 같은 자식 노드가 두번 방문되는 일은 없고, 그래서 따로 이미 방문한 노드인지 검사하는 코드는 넣지 않았다.  