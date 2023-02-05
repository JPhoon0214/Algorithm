격자판 채우기
====
<br/>

>### 문제 유형/난이도
>플레3 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1648">문제 바로 가기(baekjoon 1648)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int height, width;

vector<vector<int>> cache(20, vector<int>(40000, -1));

void makeAllCase(vector<int>& cases, int bit, int ret, int index) {
    if(index==height) {
        cases.push_back(ret);
        return;
    }    
    if(bit%2==1) {
        makeAllCase(cases, bit/2, ret, index+1);
    }
    else {
        int tempBit=1<<index;
        makeAllCase(cases, bit/2, ret+tempBit, index+1);
        bit/=2;
        if(bit%2==0 && index+1<height) {
            makeAllCase(cases, bit/2, ret, index+2);
        }
    }
}

int getCase(int level, int bit) {
    if(level<0) {
        if(bit==0) {
            return 1;
        }
        return 0;
    }

    int& ret=cache[level][bit];
    if(ret!=-1) {
        return ret;
    }

    ret=0;    
    vector<int> cases;
    makeAllCase(cases, bit, 0, 0);
    for(int i=0; i<cases.size(); i++) {
        ret+=getCase(level-1, cases[i]);
        ret%=9901;
    }
    return ret;
}

int main() {
    cin>>height>>width;
    cout<<getCase(width-1, 0);
}
```
<br/>

>### 회고
>2*n 타일 채우기, 4*n 타일 채우기와 비슷한 문제였다. 조금 다른 점은 높이가 정해져 있지 않다는 점이었다. 그 동안은 한 모양에서 다음 모양으로 전이가 가능한 모든 경우를 그림으로 그려 보면서 문제를 해결했었는데, 이번에는 높이가 정해져 있지 않기 때문에 전이가 가능한 모든 경우를 반환해주는 완전탐색 함수를 작성하였다. 높이가 최대 14이기 때문에 완전 탐색으로 가능한 경우를 찾더라도 시간/메모리 초과가 나지 않을 거라 생각했다. 다만 코드를 작성하던 중에 비트의 순서를 반대로 적는 실수를 범해 디버깅 하는데 시간이 조금 걸렸다. 다음부터 헷갈리지 않도록 꼼꼼히 적어두고 설계한 다음 문제를 해결해야겠다.