소형기관차
====
<br/>

>### 문제 유형/난이도
>골드3 / DP, 부분합
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2616">문제 바로 가기(baekjoon 2616)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(50001, vector<int>(3, -1));
vector<int> sumValue;

int getMax(int smallLinked, int index, int picked) {
    if(picked==3) {
        return 0;
    }
    if(index>=sumValue.size()) {
        return -987654321;
    }
    int& ret=cache[index][picked];
    if(ret!=-1)
        return ret;

    ret=-987654321;
    ret=max(sumValue[index]+getMax(smallLinked, index+smallLinked, picked+1), getMax(smallLinked, index+1, picked));
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> value(n);
    for(int i=0; i<n; i++) {
        cin>>value[i];
    }
    int smallLinked;
    cin>>smallLinked;

    int smallSum=0;
    for(int i=0; i<smallLinked; i++) {
        smallSum+=value[i];
    }
    sumValue.push_back(smallSum);
    for(int i=smallLinked; i<n; i++) {
        smallSum+=value[i];
        smallSum-=value[i-smallLinked];
        sumValue.push_back(smallSum);
    }

    cout<<getMax(smallLinked, 0, 0);
}

```
<br/>

>### 회고
>역시 군대가 공부하기 좋은 환경은 아닌 것 같다... 주위가 너무 시끄러워 집중을 하지 못해 푸는데 꽤나 많은 시간이 걸렸다.
>
>우선 부분합을 이용해 소형 기관차가 끌 수 있는 길이의 열차를 묶어 그 안에 탈 수 있는 승객의 수를 저장하는 벡터를 n의 시간에 구할 수 있었다<br>
>이 문제는 푸는 방식에 따라 시간초과가 날 수도 있는 문제이다. 나는 cache[i][j]=i번째 이후로 j번째 소형 기관차가 끌 열차 그룹을 고를 때 태울 수 있는 최대 승객의 수를 저장하도록 했다.
> >이때 cache[i][j]=max(cache[i+소형기관차가 끌 수 있는 열차 길이][j]+[i]번째 열차그룹에 태울 수 있는 승객 수, cache[i+1][j])가 된다.
>만약 cache[i][j]를 i번째 열차를 j번째 소형 기관차가 끌 때 태울 수 있는 승객의 최소값으로 정한다면, 반복문을 사용하여야 한다. 소형 기관차가 끌 수 있는 열차 길이를 k라고 한다면
> >cache[i][j]=max(cache[i+k][j+1], cache[i+k+1][j+1], cache[i+k+2][j+1] ...)+[i]번째 열차 그룹에 태울 수 있는 승객 수 가 된다.
>이때 두번째 방법으로 풀이한다면 반복문이 사용되어 최대 3*n개의 부분문제가 존재하고, 한 부분문제가 O(n)의 시간에 계산되므로, n이 최대 5만인 이 문제에서는 시간초과를 발생시킨다.