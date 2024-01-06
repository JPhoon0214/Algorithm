제곱수 찾기
====
<br/>

>### 문제 유형/난이도
>골드5 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1025">문제 바로 가기(baekjoon 1025)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;

vector<int> allNums;

vector<int> dxs;
vector<int> dys;

void startThisPlace(int currX, int currY, int dx, int dy, int bef, vector<string>& map) {
    int nextX=currX+dx;
    int nextY=currY+dy;

    if(nextX<0 || nextX>m-1 || nextY<0 || nextY>n-1) return;

    int curr=10*bef+(map[nextY][nextX]-'0');
    allNums.push_back(curr);
    startThisPlace(currX+dx, currY+dy, dx, dy, curr, map);
}

void makeCases(vector<string>& map) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            allNums.push_back(map[i][j]-'0');
            if(map[i][j]=='0') continue;

            for(int k=0; k<dxs.size(); k++) {
                startThisPlace(j, i, dxs[k], dys[k], map[i][j]-'0', map);
            }
        }
    }
}

int main() {
    cin>>n>>m;
    vector<string> map(n);

    for(int i=0; i<n; i++) cin>>map[i];

    for(int i=-n; i<=n; i++) {
        for(int j=-m; j<=m; j++) {
            if(i==0 && j==0) continue;

            dxs.push_back(j);
            dys.push_back(i);
        }
    }

    makeCases(map);

    sort(allNums.begin(), allNums.end());
    
    int allNumPointer=0;
    int ret=-1;
    int i=0;

    while(allNumPointer<allNums.size()) {
        int currPow=pow(i, 2);

        if(currPow==allNums[allNumPointer]) {
            ret=currPow;
            allNumPointer++;
            i++;
        }             
        else if(currPow<allNums[allNumPointer]) {
            i++;
        }
        else {
            allNumPointer++;
        }
    }

    cout<<ret;
}
```
<br/>

>### 회고
>오늘도 역시 코드가 별로 맘에 들지는 않는다.  
>그래도 이번 코드는 짧은 시간 안에 빠르게 짜야 했던 상황이라 어쩔 수 없었다고 생각한다.  
>처음에 시간 초과가 나서 쓸데 없이 중복되는 부분을 리펙토링 해보긴 했는데 유의미한 결과가 나오진 않았다.  
>별로 시간이 줄어들지 않은 거 같은데 시간 안에 통과했다.  
>처음 코드도 계산해 봤을때 시간 초과가 날만한 코드가 아니었는데 사실 `dxs`와 `dys`에 각각 j와 i를 푸쉬했어야 했는데 반대로 i와 j를 푸쉬하는 실수가 있었다.  
>그런데 왜 틀렸습니다가 아니라 시간 초과가 났는지 모르겠군...재귀 함수의 기저사례에 걸리지 않아 재귀함수가 무한 반복 했거나 내 계산보다 훨씬 많이 실행된 것이 아닐까 의심중인데 잘 모르겠다.  
>결과적으로 굳이 코드를 리펙토링 할 필요는 없었고 그냥 버그만 잡았으면 됐을 거 같다.  
>마지막에 제곱수인지 검사하는 부분에서 쉽게 생각할 수 있는 i를 증가하면서 제곱해 비교해 보는 방식으로 코드를 짜면 시간초과가 날 것 같아서 투포인터를 응용한 방식으로 시간을 줄였다.  