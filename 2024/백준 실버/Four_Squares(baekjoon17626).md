Four Squares  

>### 문제 유형/난이도
>실버3 / DP  

>### 문제
> <a href="https://www.acmicpc.net/problem/7626">문제 바로 가기(baekjoon 7626)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXVALUE=987654321;

vector<int> cache(50001, -1);

int getMinSqNums(int input, int remain) {
    if(input<0) return MAXVALUE;
    if(cache[input]!=-1) return cache[input];
    if(remain==0) {
        if(input==0) return 0;
        else return MAXVALUE;
    }
    if(input==0) return 0;

    int sqrinput=(sqrt(input))+1;

    int& ret=cache[input];
    ret=MAXVALUE;
    for(int i=1; i<=sqrinput; i++) {
        ret=min(getMinSqNums(input-i*i, remain-1), ret);
    }
    ret+=1;
    return ret;
}

int main() {
    int input;
    cin>>input;

    cout<<getMinSqNums(input, 4);
}
```

>### 회고
> 태그에 브루트 포스도 붙어 있었는데 그냥 디피로 풀었다. 브루트 포스로도 풀 수 있는 문제라면 브루트 포스로 푸는게 맞다고 생각하지만, 이 문제에선 문제를 푸는 시간보다 브루트 포스로 풀어도 된다는걸 계산하는게 더 부담이 되어서 디피로 풀었다. 이번엔 참조값을 이용해 cache[input]를 ret에 담아 이용해 보았다.
