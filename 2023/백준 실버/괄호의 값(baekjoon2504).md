괄호의 값
====
<br/>

>### 문제 유형/난이도
>실버1 / 스택
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2504">문제 바로 가기(baekjoon 2504)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isAvail=true;

long long calRet(string input) {
    if(input.size()==0)
        return 1;
    
    stack<char> lets;
    int index=0;
    long long ret=0;
    
    while(index<input.size()) {
        long long smallRet=input[index]=='(' ? 2 : 3;
        lets.push(input[index++]);
        int begin=index;
        int countLet=0;
        while(index<input.size() && !lets.empty()) {
            char currLet=input[index];
            if(currLet=='(' || currLet=='[') {
                lets.push(currLet);
            }
            else {
                if(currLet==')' && lets.top()=='(') {
                    lets.pop();
                }
                else if(currLet==']' && lets.top()=='[') {
                    lets.pop();
                }
                else {
                    isAvail=false;
                }
            }
            countLet++;
            index++;
        }
        if(!lets.empty()) {
            isAvail=false;
        }
        
        smallRet*=calRet(input.substr(begin, countLet-1));
        ret+=smallRet;
    }
    return ret;
}

int main() {
    string input;
    cin>>input;
    long long ret=calRet(input);;
    if(isAvail)
        cout<<ret;
    else
        cout<<0;
}
```
<br/>

>### 회고
>인터넷에서 어떤 분이 정리해주신 백준 문제 선정 로드맵을 찾아, 이 순서대로 문제를 풀어 볼 생각이다.
> <a href="https://covenant.tistory.com/224">사이트 바로가기</a>
> 준비운동 PART1은 처음 시작할 때 풀었으면 좋았겠지만, 지금은 조금 더 어려운 문제를 풀어보는 것이 좋을 것 같아 건너뛰었다. PART2 약점 체크에는 적당한 수준의 문제들을 정리해 놓으셨고, 약간 구현 능력에 초점을 둔 문제들을 선정해 놓으신 것 같았다.<br/>
> PART2의 첫번째 문제는 이전에 풀어 보기도 했고, 손쉽게 풀 수 있을 것 같아 두번째 문제부터 풀기 시작했다.
> 스택을 이용해 괄호가 열렸다가 닫히는 범위를 검사하고, 그렇게 찾아낸 구간의 가장 바깥 쪽 괄호를 제거하고 재귀함수로 나머지 문자열을 넘기는 방식으로 구현하였다. 자료구조를 효과적으로 이요하기 보다 재귀함수를 이용한 풀이 방식으로 문제를 해결했다. 재귀 함수가 생각만큼 깔끔해보이진 않는데, 나중에 다른 풀이 방법을 고민해 보고, 다른 분들이 어떻게 풀었는지도 한번 배워봐야겠다.<br/>
> 오늘 부대 선후임들과 오랜만에 풋살을 했는데, 후유증이 심하게 와서 알고리즘은 간단히 공부하고 마무리했다. 처음엔 알고리즘 문제 풀이 로그를 남기는 것이 시간 낭비가 되지 않을까 생각했는데, 생각보다 얻어가는 것도 많고, 무엇보다 좀 재밌는 것 같다.