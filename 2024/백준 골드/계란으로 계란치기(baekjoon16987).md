계란으로 계란치기
====
<br/>

>### 문제 유형/난이도
>골드5 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/16987">문제 바로 가기(baekjoon 16987)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int eggNum;

int getBreakEggs(vector<pair<int, int>>& eggInfos) {
    int cnt=0;
    vector<pair<int, int>>::iterator iter=eggInfos.begin();

    while(iter!=eggInfos.end()) {
        if((*iter).first<=0) cnt++;
        iter++;
    }

    return cnt;
}

int getMaxBreak(vector<pair<int, int>>& eggInfos, int currEgg) {
    if(currEgg==eggNum) {
        return getBreakEggs(eggInfos);
    }
    if(eggInfos[currEgg].first<=0) return getMaxBreak(eggInfos, currEgg+1);

    bool hit=false;
    int ret=0;
    for(int i=0; i<eggNum; i++) {
        if(i==currEgg) continue;
        if(eggInfos[i].first<=0) continue;

        hit=true;

        eggInfos[i].first-=eggInfos[currEgg].second;
        eggInfos[currEgg].first-=eggInfos[i].second;

        ret=max(ret, getMaxBreak(eggInfos, currEgg+1));

        eggInfos[i].first+=eggInfos[currEgg].second;
        eggInfos[currEgg].first+=eggInfos[i].second;
    }

    if(!hit) ret=getMaxBreak(eggInfos, currEgg+1);

    return ret;
}

int main() {
    cin>>eggNum;
    vector<pair<int, int>> eggInfos(eggNum);

    for(int i=0; i<eggNum; i++) {
        cin>>eggInfos[i].first>>eggInfos[i].second;
    }

    cout<<getMaxBreak(eggInfos, 0);
}
```
<br/>

>### 회고
>>원래 풀려고 했던 문제는 다른 문제였는데 도저히 왜 틀리는지 모르겠어서 한참 고민하다 일일 스트릭 깨지기 싫어서 이거라도 풀게 되었다.
>>문제가 엄청 길었는데 나름 스토리는 재밌었던거 같다.
>>이터레이터 쓸 때마다 놓치는 부분이 ++을 안해줘서 무한 반복에 빠지는 것이다. 뭔가 만성적으로 매일 빼먹는 느낌이었는데 요즘엔 그래도 하도 빼먹다 보니 반사적으로 ++가 생각나는 것 같다.
>>문제는 크게 특별한 부분은 없었지만 굳이 회고해 보자면 달걀을 한번 쳐서 내구도가 닳은 상태에서 백트래킹 하기 위해서 원상복구를 해야 했는데, 내구도가 다 닳은 달걀의 내구도를 0으로 표기하면 원상복구가 힘들어서 내구도가 음수도 가능하게 했다. 그리고 달걀이 하나만 남았는데 인덱스 상으로 가장 오른쪽에 있는 달걀이 아닐 경우 재귀함수를 끝내야 하는 상황인데 기저사례에 걸리지 않아서 `hit`이라는 플래그를 사용했다. 더 좋은 방법이 있을 거 같긴 했지만 당장 생각나는 충분히 쉬운 방법을 두고 더 멋진 방법을 찾을 필요는 없을 거 같아서 사용했다.
>>회고하다 알게 됐는데 `getBreakEggs`함수가 O(n)의 시간 복잡도를 가지기 때문에 조금 빡빡하게 시간 초과를 면한 것 같다. n이 최대 8밖에 안돼서 이렇게 풀어도 무리 없을거라 생각했는데 조금 위험했을지도.
>>달걀 개수가 1개만 더 많았어도 브루트포스 말고 다른 방법을 생각해야 했을 것이다. 지금 알고리즘은 O(n^n)의 시간 복잡도를 가져 달걀 개수가 1개 추가될 때마다 시간이 기하급수적으로 증가한다.
