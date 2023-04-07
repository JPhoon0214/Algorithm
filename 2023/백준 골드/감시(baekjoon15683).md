감시
====
<br/>

>### 문제 유형/난이도
>골드4 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2457">문제 바로 가기(baekjoon 2457)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getFlowerNum(int startDay, int endDay, vector<pair<int, int>>& infos, int infoIndex) {
    if(infoIndex>=infos.size() || infos[infoIndex].first>startDay) {
        return -987654321;
    }
    
    int lastDay=-1;
    
    for(; infoIndex<infos.size()&&infos[infoIndex].first<=startDay; infoIndex++) {
        lastDay=max(lastDay, infos[infoIndex].second);
    }

    if(lastDay>endDay) {
        return 1;
    }
    else {
        return getFlowerNum(lastDay, endDay, infos, infoIndex)+1;
    }
}

int main() {
    vector<int> monthToDay(12, 0);
    for(int i=1; i<12; i++) {
        monthToDay[i]=monthToDay[i-1]+month[i-1];
    }

    int n;
    cin>>n;

    vector<pair<int, int>> infos(n);

    for(int i=0; i<n; i++) {
        int sMonth, sDay;
        int eMonth, eDay;

        cin>>sMonth>>sDay>>eMonth>>eDay;

        infos[i]=pair<int, int>({monthToDay[sMonth-1]+sDay, monthToDay[eMonth-1]+eDay});
    }
    
    sort(infos.begin(), infos.end());

    int startDay=monthToDay[2]+1;
    int endDay=monthToDay[10]+30;

    int ret=getFlowerNum(startDay, endDay, infos, 0);

    if(ret<=0) {
        cout<<0;
    }
    else {
        cout<<ret;
    }
}
```
<br/>

>### 회고
>>그리디보다도 빡구현 느낌이 조금 나는 문제였다. 그동안 날짜 처리를 해주는 것이 너무 귀찮을 것 같아서 한동안 안풀고 남겨두다가 한번 해 보았는데 생각만큼 까다롭진 않았다. 알고리즘 적용 뿐만 아니라 단순 구현에도 더욱 익숙해져야겠다.