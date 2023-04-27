스터디 그룹
====
<br/>

>### 문제 유형/난이도
>플레5 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14572">문제 바로 가기(baekjoon 14572)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getValue(int stdNum, vector<int>& state) {
    int cnt=0;
    for(int i=0; i<state.size(); i++) {
        if(state[i]>0 && state[i]<stdNum) {
            cnt++;
        }
    }
    return cnt*stdNum;
}

void setState(vector<pair<int, int>>& stdValue, vector<vector<int>>& stdKnowAlgo, vector<int>& state, int ptr, int flag) {
    int currPtr=stdValue[ptr].second;
    for(int i=0; i<stdKnowAlgo[currPtr].size(); i++) {
        int currAlgoIndex=stdKnowAlgo[currPtr][i];
        state[currAlgoIndex]+=flag;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int stdNum, algoNum, availGap;
    cin>>stdNum>>algoNum>>availGap;

    vector<pair<int, int>> stdValue(stdNum);
    vector<vector<int>> stdKnowAlgo(stdNum, vector<int>());

    for(int i=0; i<stdNum; i++) {
        int currKnowAlgoNum;
        cin>>currKnowAlgoNum>>stdValue[i].first;
        stdValue[i].second=i;

        for(int j=0; j<currKnowAlgoNum; j++) {
            int algoIndex;
            cin>>algoIndex;
            stdKnowAlgo[i].push_back(algoIndex-1);
        }
    }

    sort(stdValue.begin(), stdValue.end());

    int ret=0;

    int startPoint=0, endPoint=0;
    vector<int> state(algoNum, 0);

    setState(stdValue, stdKnowAlgo, state, 0, 1);

    while(true) {
        if(stdValue[endPoint].first-stdValue[startPoint].first>availGap) {
            setState(stdValue, stdKnowAlgo, state, startPoint, -1);
            startPoint++;
            continue;
        }

        ret=max(ret, getValue(endPoint-startPoint+1, state));

        endPoint++;
        if(endPoint>=stdNum) break;
        setState(stdValue, stdKnowAlgo, state, endPoint, 1);        
    }
    
    cout<<ret;
}
```
<br/>

>### 회고
>아이디어보다 구현이 조금 더 어려웠던거 같기도 하다.
>실력 순서대로 정렬한 후 투 포인터를 이용해 탐색을 할 경우 선형 시간 안에 최적일 수 있는 모든 경우의 수를 탐색할 수 있다. 만약 어떤 한 사람을 포함하기로 한 상황에서 가능한 최대한 많은 스터디원을 모으는 것이 효율성을 최대화 하는데 손해일 수 없다는 것은 쉽게 알 수 있다. 따라서 실력순으로 정렬한 상황에서 투포인터로 가리키는 두 지점 사이에는 start가 가리키는 사람을 포함하는 최대한 많은 스터디원을 가진 상황이 모두 고려된다. 이 상황에서 getValue() 함수를 이용해 효율성을 구한 후, 이를 반복해 최대 효율성을 출력했다. end포인터를 옮기는 상황과 start포인터를 옮기는 상황 모두 현재 그룹이 알고 있는 알고리즘 목록을 갱신할 필요가 있는데, flag를 이용해 한 함수에서 처리하도록 했다.