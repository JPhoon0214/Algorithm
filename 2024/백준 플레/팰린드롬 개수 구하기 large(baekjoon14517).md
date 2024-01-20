팰린드롬 개수 구하기 large
====

>### 문제 유형/난이도
>플레5 / DP

>### 문제
> <a href="https://www.acmicpc.net/problem/14517">문제 바로 가기(baekjoon 14517)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > cache(1000, vector<int>(1000, -1));

int getCaseNum(int left, int right, string& str) {
    if(cache[left][right]!=-1) return cache[left][right];
    if(left==right) return cache[left][right]=1;
    if(left+1==right) {
        if(str[left]==str[right]) return 3;
        return 2;
    }

    cache[left][right]=getCaseNum(left+1, right, str)+getCaseNum(left, right-1, str);
    cache[left][right]%=10007; 
    cache[left][right]+=10007;

    if(str[left]!=str[right]) {
        cache[left][right]-=getCaseNum(left+1, right-1, str);
    }
    else {
        cache[left][right]+=1;
    }

    cache[left][right]%=10007;

    return cache[left][right];
}

int main() {
    int ret=0;
    string str;
    cin>>str;

    cout<<getCaseNum(0, str.size()-1, str);
}
```

>### 회고
오늘 친구들이 같이 공부하자며 집에 방문해서 강의를 듣기는 애매해져 알고리즘 공부로 방향을 틀었다. 고민이 좀 많았는데 고민한 것 치고는 그럭저럭 쉽게 푼 문제이다.  
cache[i][j]를 [i, j] 사이 구간의 팰린드롬의 개수라고 정의한다면 cache[i][j]는 다음과 같은 과정을 거쳐 구할 수 있다.  
    - 문자열의 i번째 글자와 j번째 글자가 같은 경우  
        1 기존 [i+1, j-1] 구간의 모든 팰린드롬의 양쪽 끝에 각각 i번째 글자와 j번째 글자를 붙여 새로운 팰린드롬을 만들 수 있다. 따라서 cache[i+1][j-1]을 더한다. 이때 만들어진 팰린드롬 수는 새로운 문자가 양쪽 끝에 붙었기 때문에 모두 새로운 팰린드롬이다.  
        2 [i+1, j] 구간의 팰린드롬은 원래 존재하던 팰린드롬과 새로운 문자 j가 포함된 팰린드롬이 섞여 있다. 이 역시 [i, j] 구간에 포함되는 팰린드롬 이므로 cache[i+1][j]를 더해준다.  
        3 2와 동일한 논리로 cache[i][j-1]을 더해준다.  
        4 오직 i번째 문자와 j번째 문자만을 가진 크기가 2짜리 팰린드롬이 1개 생성된다. 따라서 1을 더해준다.  
        5 2와 3의 과정에서 i와 j 모두를 포함하지 않는, 기존에 존재하던 팰린드롬은 두번 더해졌기 때문에 cache[i+1][j-1]을 빼준다.  
        따라서 cache[i][j]=cache[i+1][j]+cache[i][j-1]+1이 된다.  
    - 문자열의 i번째 글자와 j번째 글자가 다른 경우  
        1 [i+1, j] 구간의 팰린드롬은 원래 존재하던 팰린드롬과 새로운 문자 j가 포함된 팰린드롬이 섞여 있다. 이 역시 [i, j] 구간에 포함되는 팰린드롬 이므로 cache[i+1][j]를 더해준다.  
        2 1과 동일한 논리로 cache[i][j-1]을 더해준다.  
        3 1과 2의 과정에서 i와 j 모두를 포함하지 않는, 기존에 존재하던 팰린드롬은 두번 더해졌기 때문에 cache[i+1][j-1]을 빼준다.  
다만 위와 같은 과정을 거쳐 답을 구하면 left(i)와 right(j)가 같을 때 뿐만 아니라 1차이가 날때도 처리해 줘야 하는데, 중간에 cache[i+1][j-1]을 구하는 과정에서 left==right을 지나쳐 버리는 경우가 존재하기 때문이다. 또한 나머지 처리에도 신경을 써야 하는데 별다른 처리 없이 나머지를 구하면 `-=getCaseNum(left+1, right-1, str);` 부분에서 문제가 발생할 수 있다.
