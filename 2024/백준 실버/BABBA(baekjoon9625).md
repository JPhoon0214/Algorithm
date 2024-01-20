BABBA  

>### 문제 유형/난이도
>실버5 / DP  

>### 문제
> <a href="https://www.acmicpc.net/problem/9625">문제 바로 가기(baekjoon 9625)</a>

<br/>

>### 코드
```C++
#include <iostream>

using namespace std;

void printABNum(int aNum, int bNum, int remain) {
    if(remain==0) {
        cout<<aNum<<" "<<bNum;
        return;
    }
    printABNum(bNum, aNum+bNum, remain-1);
}

int main() {
    int k;
    cin>>k;
    printABNum(1, 0, k);
}
```

>### 회고
>큰일이다. 알고리즘 스터디 공통 문제로 선정한 문제인데 이런 문제였을 줄이야. 선정할 때 문제를 자세히 읽어보고 정해야 했다. 왜 이렇게 됐더라...저번 스터디에서...기억은 잘 안나는데 떠들면서 문제를 선정하는 바람에 이렇게 된 것 같다. 아니 이게 어째서 DP 태그가 붙어 있는 거야. 난이도 기여에 가서 구현 태그 붙이고 왔다. 사실 다들 DP라 하는데 구현 태그만 붙이기엔 좀 그래서 일단 DP 태그도 붙이긴 했다. DP로 풀수 없는 건 아니지만 DP로 풀 필요가 없는 문제를 왜 굳이 DP로 풀어야 한다는 말인가. 그냥 아무 생각 없이 재귀함수를 돌리거나 반복문 한줄로도 풀릴만한 문제다. 더 쉽고 빠르며 안틀리게 풀 수 있는 방법을 두고 DP로 푸는 것은 이해할 수 없다. 스터디원들 이문제 어떻게 풀어오려나...조금 걱정이다.
