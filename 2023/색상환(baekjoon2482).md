색상환
====
<br/>

>### 문제 유형/난이도
>골드4 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2482">문제 바로 가기(baekjoon 2482)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache(1001, vector<long long>(1001, -1));
int totalColor, totalToPick;

long long getRet(int remainNum, int toPick) {
    if(toPick==0)
        return 1;
    if(remainNum<toPick)
        return 0;
    
    if(cache[remainNum][toPick]!=-1)
        return cache[remainNum][toPick];

    long long ret=0;
    for(int i=remainNum; i>0; i--) {
        int nextRemain=i-2;
        ret+=getRet(nextRemain, toPick-1);
        ret%=1000000003;
    }
    return cache[remainNum][toPick]=ret;
}

int main() {
    cin>>totalColor>>totalToPick;
    long long ret=getRet(totalColor-3, totalToPick-1); //원으로 되어 있는 색상환의 첫번째 원소를 고르는 경우
    for(int i=1; i<totalColor; i++) {
        ret+=getRet(totalColor-i-2, totalToPick-1); //두번째 원소부터는 평순열과 동일
        ret%=1000000003;
    }
    cout<<ret;
}
```
<br/>

>### 회고
>내가 생각한 문제 해결 아이디어는 그리 복잡하진 않았다. 원으로 되어 있는 색상환에서 위치를 이용해서 DP를 적용할 경우, 시작하는 색과 끝나는 색이 사실상 연결되어 있어 이를 처리해줘야 하는 불편함이 있었다. 이 때문에 색생환 상 위치 대신 고를 수 있는 색과 골라야 하는 색을 이용해 이차원 벡터를 만들어 중간값을 저장했다. 하지만 이렇게 고안하니 기저사례를 설정하는데 조금의 애로사항이 있었다. 기저사례를 설정하는데 조금 더 신경써야겠다.