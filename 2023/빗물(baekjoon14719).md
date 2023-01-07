빗물
====
<br/>

>### 문제 유형/난이도
>골드5 / 구현
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14719">문제 바로 가기(baekjoon 14719)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int getWaterHeight(vector<int>& heights, int index) {
    int maxLeft=0;
    for(int i=index-1; i>=0; i--) {
        if(heights[i]>heights[index]) {
            maxLeft=max(heights[i], maxLeft);
        }
    }

    int maxRight=0;
    for(int i=index+1; i<heights.size(); i++) {
        if(heights[i]>heights[index]) {
            maxRight=max(heights[i], maxRight);
        }
    }

    int ret=min(maxLeft, maxRight)-heights[index];
    ret=ret>=0 ? ret : 0;
    
    return ret;
}

int main() {
    int ret=0;
    int h, w;
    cin>>h>>w;
    vector<int> heights(w);
    for(int i=0; i<w; i++) {
        cin>>heights[i];
    }
    for(int i=0; i<w; i++) {
        ret+=getWaterHeight(heights, i);
    }
    cout<<ret;
}
```
<br/>

>### 회고
>앞서 말했던 백준 문제 풀이 순서를 추천해주는 사이트에 있는 문제이다.
>입력의 크기가 작아 어떻게 구현해도 거의 정답을 받을 만한 문제였다.
>단순히 2중 반복문을 이용해 현재 깊이 기준으로 왼쪽과 오른쪽에서 가장 높은 높이를 저장한다.
>이후 왼쪽 값과 오른쪽 값 중 더 작은 값을 기준과 비교해 기준보다 더 높다면 기준과의 차이를 리턴해준다.
>만약 입력의 크기가 더 커진다면 DP등의 방법으로도 해결할 수 있을 것 같다.