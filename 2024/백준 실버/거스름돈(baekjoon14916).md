수 이어가기
====
<br/>

>### 문제 유형/난이도
>실버5 / dp
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14916">문제 바로 가기(baekjoon 14916)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int MAXCOIN=987654321;

vector<int> cache(100001, MAXCOIN);

int getCoinNum(int money) {
    if(money<0) return MAXCOIN;
    if(money==0) return 0;
    if(cache[money]!=MAXCOIN) return cache[money];

    cache[money]=min(getCoinNum(money-2), getCoinNum(money-5))+1;
    return cache[money];
}

int main() {
    int money;
    cin>>money;
    
    int ret=getCoinNum(money);
    ret<MAXCOIN ? cout<<ret : cout<<-1;
}
```
<br/>

>### 회고
>스터디 하면서 푼 문제이다. 평소처럼 cache를 -1로 초기화 하고 싶었는데, 최소 값을 구하는 로직 상 -1일때 예외 처리를 해주기 귀찮아서 그냥 아주 큰 값을 대입했다.  
>수민 누나가 그리디로 풀었는데 조금 신기한 방법이었다. 문제를 습관적으로 풀지 말고 여러 방법을 생각해 봐야겠다.  
>맥북에서 백틱 위치를 누르면 한글이면 ₩, 영어면 백틱이 출력된다. 따라서 vscode 터미널을 열고 싶으면 영문 타자 상태에서 ctrl+백틱을 입력해야 한다.  
