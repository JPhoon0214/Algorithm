카드게임
====

>### 문제 유형/난이도
>골드3 /DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1062">문제 바로 가기(baekjoon 1062)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int getBestScore(int first, int last, vector<int>& cards, vector<vector<int> >& cache, int currSum) {
    if(cache[first][last]!=-1) return cache[first][last];
    if(first==last) return cache[first][last]=cards[first];

    int firstMoveSum=(currSum-getBestScore(first+1, last, cards, cache, currSum-cards[first]));
    int lastMoveSum=(currSum-getBestScore(first, last-1, cards, cache, currSum-cards[last]));

    return cache[first][last]=max(firstMoveSum, lastMoveSum);
}

int main() {
    int testCase;
    cin>>testCase;

    for(; testCase>0; testCase--) {
        int cardNum;
        cin>>cardNum;

        int allSum=0;

        vector<int> cards(cardNum);
        for(int i=0; i<cardNum; i++) {
            cin>>cards[i];
            allSum+=cards[i];
        }

        vector<vector<int> > cache(cardNum, vector<int>(cardNum, -1));
        cout<<getBestScore(0, cardNum-1, cards, cache, allSum)<<"\n";
    }
}
```
<br/>

>### 회고
>예전에 비슷한 문제를 풀어봤던 것 같은데 그때는 DP 문제가 아니었다.  
>처음 아이디어를 고민하는데는 얼마 안 걸렸는데, 구체적으로 어떻게 동작하는지 설계하는데 오래 걸렸다.  
>부분합을 구해 저장을 할까 생각했었는데, 결과적으로 전체 합을 한번만 구하면 재귀를 통해 자연스럽게 부분합을 구할 수 있어 그럴 필요는 없었다.  
>아마 부분합을 직접 구했어도 솔브는 되지 않았을까.  
>cache[first][last] = first-last 구간의 카드만 남았을 때 낼 수 있는 점수의 최대 값이다.  