타일채우기
====
<br/>

>### 문제 유형/난이도
>골드1 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2718">문제 바로 가기(baekjoon 2718)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int calCaseNum(vector<vector<int>>& cache, int remainWidth, int type);

int calCase0(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-2, 0);
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-1, 1);
    ret+=calCaseNum(cache, remainWidth-1, 2);
    ret+=calCaseNum(cache, remainWidth-1, 3);
    return ret;
}

int calCase1(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-1, 2);
    return ret;
}

int calCase2(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-1, 1);
    return ret;
}

int calCase3(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-2, 3);
    return ret;
}


int calCaseNum(vector<vector<int>>& cache, int remainWidth, int type) {
    if(remainWidth<0) {
        return 0;
    }
    if(remainWidth==0 && type==0) {
        return 1;
    }
    
    int& ret=cache[remainWidth][type];
    if(ret!=-1) {
        return ret;
    }
    
    if(type==0) {
        ret=calCase0(cache, remainWidth);
    }
    else if(type==1) {
        ret=calCase1(cache, remainWidth);
    }
    else if(type==2) {
        ret=calCase2(cache, remainWidth);
    }
    else if(type==3) {
        ret=calCase3(cache, remainWidth);
    }
    return ret;
}

int main() {
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        int width;
        cin>>width;
        vector<vector<int>> cache(width+1, vector<int>(5, -1));
        cout<<calCaseNum(cache, width, 0)<<"\n";
    }
}
```
<br/>

>### 회고
>2*n 타일링의 경우 굳이 만들 수 있는 블록 모양을 생각할 필요가 없었지만, 이번 문제에서는 어떤 블록 모양들이 가능할 지 상상해보면서 풀어야 했다. 중복되지 않게 경우의 수를 세기 위해 총 4가지 모양을 구상했고, 각각의 모양을 관리하는 함수를 따로 만들어 디버깅이 쉽도록 하였다. 하지만 차라리 한 함수에 깔끔하게 집어넣는게 나았을지도 모르겠다... 풀면서 다형성을 이용해 풀면 조금 더 편리하게 코드를 짜겠다는 생각이 들긴 했지만, 우선은 빠르게 푸는 것에 의의를 두고 코드가 조금 길어지더라도 직관적으로 코드를 작성해 보았다.