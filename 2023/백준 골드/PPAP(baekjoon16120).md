PPAP
====
<br/>

>### 문제 유형/난이도
>골드4 / 그리디, 스택
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/16120">문제 바로 가기(baekjoon 16120)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

bool checkPPAP(vector<char>& lets) {
    if(lets.size()<4) {
        return false;
    }

    string target="PPAP";
    
    for(int i=lets.size()-4; i<lets.size(); i++) {
        if(lets[i]!=target[i-(lets.size()-4)]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    cin>>input;

    vector<char> temp;

    for(int i=0; i<input.size(); i++) {
        temp.push_back(input[i]);
        while(checkPPAP(temp)) {
            for(int i=0; i<4; i++) {
                temp.pop_back();
            }
            temp.push_back('P');
        }
    }

    if(temp.size()==1 && temp[0]=='P') {
        cout<<"PPAP";
    }
    else {
        cout<<"NP";
    }
}
```
<br/>

>### 회고
>그리디를 공부하는 중이었는데 막상 해결해보니 그리디보단 스택을 이용해 해결한 것 같다. 스택을 활용한 유명한 문제인 괄호 검사 등의 문제가 떠오르는 문제였다. 문제에서 제시한 것과 반대로 주어진 문자열을 원본으로 바꾼 후 원본 문자열이 P와 동일한지 검사하는 방식으로 문제를 해결했다.