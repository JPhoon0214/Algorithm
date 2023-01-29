박성원
====
<br/>

>### 문제 유형/난이도
>플레5 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1086">문제 바로 가기(baekjoon 1086)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int divider;
int inputNum;
vector<string> inputs(20);
vector<int> remains(20);
vector<int> levelCache(60);

int getRemain(string num, int ret) {
    if(num.empty())
        return ret;
    
    int currNum=num[0]-'0';
    ret*=10;
    ret+=currNum;
    ret%=divider;
    return getRemain(num.substr(1), ret);
}

void setCache(vector<vector<long long>>& cache, int alreadySelected, int currSelected, int level) {
    for(int i=0; i<divider; i++) {
        int currStrSize=inputs[level].size();
        int nextRemain=i;
        /*
        for(int strSize=0; strSize<currStrSize; strSize++) {
            nextRemain*=10;
            nextRemain%=divider;
        }*/
        nextRemain*=levelCache[currStrSize];
        nextRemain%=divider;
        nextRemain+=remains[level];
        nextRemain%=divider;
        cache[alreadySelected+currSelected][nextRemain]+=cache[alreadySelected][i];
    }
}

long long getGreatestCommonDivisor(long long bigger, long long smaller) {
    if(bigger%smaller==0)
        return smaller;
    return getGreatestCommonDivisor(smaller, bigger%smaller);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>inputNum;
    for(int i=0; i<inputNum; i++) {
        cin>>inputs[i];
    }
    
    cin>>divider;
    for(int i=0; i<inputNum; i++) {
        string target=inputs[i];
        remains[i]=getRemain(target, 0);
    }

    int levelTemp=10;
    levelTemp%=divider;
    levelCache[1]=levelTemp;
    for(int i=2; i<60; i++) {
        levelCache[i]=levelCache[i-1];
        levelCache[i]*=levelTemp;
        levelCache[i]%=divider;
    }

    vector<vector<long long>> cache(32768, vector<long long>(100, 0));
    cache[0][0]=1;

    int allChoose=1<<inputNum;
    for(int selected=0; selected<allChoose; selected++) {
        int tempSelected=selected;
        int level=0;
        while(tempSelected!=0) {
            if(tempSelected%2==1) {
                int target=1<<level;
                setCache(cache, selected-target, target, level);
            }
            tempSelected/=2;
            level++;
        }
    }

    long long totalCase=1;
    for(int i=1; i<=inputNum; i++) {
        totalCase*=i;
    }
    long long ret=cache[allChoose-1][0];

    if(ret==0) {
        cout<<"0/1";
    }
    else {
        long long divisor=getGreatestCommonDivisor(totalCase, ret);
        ret/=divisor; totalCase/=divisor;
        cout<<ret<<"/"<<totalCase;
    }
}
```
<br/>

>### 회고
>한참을 고민한 문제지만, 결국 아이디어가 도무지 생각이 나지 않아 다른 사람들의 아이디어를 조금 살펴보았다. 비트마스킹을 이런식으로 활용할 생각을 하지 못한 점이 조금 아쉬웠다. 그 부분을 제외하고는 아이디어는 얼추 맞았다고 생각한다. 또 아쉬운 점이라면, 평소 연습중이던 재귀 함수를 이용한 DP 방식이 아닌 반복문을 이용한 DP를 사용했는데, 이것은 반복문의 활용 경험을 쌓기 위해서가 아닌, 재귀로 이 문제를 해결할 자신이 없어서 선택한 차선책이었다. 또한 처음 구현을 했을 때 시간초과가 발생했고, 이 때문에 10, 100, 1000, ...을 주어진 수로 나눈 나머지를 저장하는 levelCache를 따로 관리해 시간을 줄여야 했다. 그래도 직접 풀어보는 것에 의의를 두어 다른 사람들의 코드를 자세히 보진 않았는데, 아마 나처럼 구현하진 않았을 것 같다. 간신히 정답을 받긴 했지만, 다른 사람들의 코드를 보면서 배워야겠다.