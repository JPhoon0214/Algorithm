디지털 카운터
====

>### 문제 유형/난이도
>플레2 / DP

>### 문제
> <a href="https://www.acmicpc.net/problem/1020">문제 바로 가기(baekjoon 1020)</a>

>### 코드
```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int numValue[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 5};

// cache[s][l][k]: 합이 s이고 길이가 l인 숫자 중에서 k00... 나 그 이후로 나오는 숫자 중 가장 먼저 나오는 수
// -1: 아직 검사 안함. -2: befMax 상황에선 불가능했음.
vector<vector<vector<long long> > > cache(150, vector<vector<long long> >(16, vector<long long>(10, -1LL)));

long long stringToLongLongConvert(string str) {
    long long ret=0LL;
    long long currLevel=1LL;
    while(!str.empty()) {
        ret+=((str.back()-'0')*currLevel);
        str.pop_back();
        currLevel*=10;
    }
    return ret;
}

// 끝에서 level 만큼 숫자를 비교했을 때 선분 개수가 같은 가장 먼저 나오는 수를 리턴. 불가능하다면 -2 리턴.
long long getBefMaxInLevel(int higherThan, int level, int targetSum) {
    if(higherThan>9 || targetSum<0) return -2;
    if(cache[targetSum][level][higherThan]!=-1) return cache[targetSum][level][higherThan];
    if(level==1) {
        for(int i=higherThan; i<10; i++) {
            if(targetSum==numValue[i]) return cache[targetSum][level][higherThan]=i;
        }
        return cache[targetSum][level][higherThan]=-2LL;
    }

    long long digitCal=1LL;
    for(int i=0; i<level-1; i++) {
        digitCal*=10;
    }

    for(int i=higherThan; i<10; i++) {
        long long currRet=getBefMaxInLevel(0, level-1, targetSum-numValue[i]);
        if(currRet==-2) continue;

        return cache[targetSum][level][higherThan]=i*digitCal + currRet;
    }
    return cache[targetSum][level][higherThan]=-2LL;
}

long long getBefMax(string input, vector<int>& linesSum) {
    int level=0;
    long long digitCal=1LL;
    while(!input.empty()) {
        int last=input.back()-'0';
        input.pop_back();
        level++;
        digitCal*=10;

        long long currRet=getBefMaxInLevel(last+1, level, linesSum[input.size()]);
        if(currRet!=-2) return stringToLongLongConvert(input)*digitCal+currRet;
    }
    return -1LL;
}

long long getAftMaxInLevel(int lowerThan, int level, int targetSum) {
    if(lowerThan<0 || targetSum<0) return -3LL;
    if(cache[targetSum][level][lowerThan]==-2) cache[targetSum][level][lowerThan]=-1;
    if(cache[targetSum][level][lowerThan]!=-1) return cache[targetSum][level][lowerThan];
    if(level==1) {
        for(int i=0; i<=lowerThan; i++) {
            if(targetSum==numValue[i]) return cache[targetSum][level][lowerThan]=i;
        }
        return cache[targetSum][level][lowerThan]=-3LL;
    }

    long long digitCal=1LL;
    for(int i=0; i<level-1; i++) {
        digitCal*=10;
    }

    for(int i=0; i<=lowerThan; i++) {
        long long currRet=getAftMaxInLevel(9, level-1, targetSum-numValue[i]);
        if(currRet==-3) continue;

        return cache[targetSum][level][lowerThan]=i*digitCal + currRet;
    }
    return cache[targetSum][level][lowerThan]=-3LL;
}

long long getAftMax(string input, vector<int>& linesSum) {
    int level=0;
    long long digitCal=1LL;
    long long ret=-1LL;
    while(!input.empty()) {
        int last=input.back()-'0';
        input.pop_back();
        level++;
        digitCal*=10;

        long long currRet=getAftMaxInLevel(last-1, level, linesSum[input.size()]);
        if(currRet!=-3) ret=stringToLongLongConvert(input)*digitCal+currRet;
    }
    return ret;
}

int main() {
    string input;
    cin>>input;

    vector<int> linesSum(input.size()+1, 0);
    for(int i=input.size()-1; i>=0; i--) {
        linesSum[i]=linesSum[i+1]+numValue[input[i]-'0'];
    }

    long long original=stringToLongLongConvert(input);
    long long maxNum=1LL;
    for(int i=0; i<input.size(); i++) maxNum*=10;

    long long retBefMax=getBefMax(input, linesSum);
    if(retBefMax!=-1) {
        cout<<retBefMax-original;
    }
    else {
        long long retAftMax=getAftMax(input, linesSum);
        if(retAftMax!=-1) {
            cout<<retAftMax+maxNum-original;
        }
        else {
            cout<<maxNum;
        }
    }
}
```

>### 회고
처음으로 푼 플레2 문제다. 기본적인 아이디어는 어제 생각했는데 구현이 생각보다 너무 복잡해서 짜는 와중에 너무 지저분해져서 다시 짠 코드다. 다른 사람들의 코드를 본 적은 없지만 난이도 기여에서 누군가 2차원 배열 얘기한거 보니 내가 푼 방법보다 쉬운 방법이 있는 모양이다. 근데 그래봐야 어려울듯. cache에 저장되는 값은 cache[s][l][k]: 합이 s이고 길이가 l인 숫자 중에서 k00... 나 그 이후로 나오는 숫자 중 가장 먼저 나오는 수 이다. 다만 카운터가 MAXNUMBER을 초과하기 전과 후로 나눌 필요가 있었다. 예를 들어 `27`의 경우 일의 자리 숫자를 8, 9를 탐색한 후 0으로 돌아가기 전에 십의 자리 숫자 2를 3으로 증가시키고 일의 자리를 다시 0부터 증가시켜야 한다. 28 - 29 - 20 이런 순으로 카운터가 작동하지 않는다는 뜻이다. 이를 처리해주는게 조금 복잡했다. 처음엔 함수 하나에서 처리하려 했는데 아직 내 실력으론 조금 어려워서 그냥 케이스를 두개로 나눠서 함수를 두개씩 만들었다. 27의 예시를 가지고 로직을 설명해보면 우선 일의 자리만 검사를 한다. 일의 자리 7과 선분의 개수가 같은 숫자가 7보다 큰 수, 즉 8 또는 9 중에 있다면 28 혹은 29가 정답이 된다. 이 중에 선분의 개수가 같은 경우가 없다면 이번엔 27과 선분의 개수가 같은 수를 30부터 찾는다. 십의 자리가 2인 경우는 이전에 처리한 셈이기 때문이다. 만일 99까지 찾는 수가 없다면 최대 숫자를 초과해 0부터 다시 찾아야 한다. 이는 두번째 함수에서 처리한다. 두 함수 모두 걸리지 않는다면 자기 자신 외엔 선분의 개수가 같은 숫자가 없는 경우로 이 경우엔 한바퀴 돌아 다시 자신이 나올때까지 눌러야 하는 카운터 횟수를 출력한다.
