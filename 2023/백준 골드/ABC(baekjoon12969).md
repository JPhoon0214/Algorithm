ABC
====
<br/>

>### 문제 유형/난이도
>골드1 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/12969">문제 바로 가기(baekjoon 12969)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char cache[30][30][30][30][450];
vector<char> retStr;
int strLen;

int getRet(int index, int aNum, int bNum, int cNum, int target) {
    if(index==strLen) {
        if(target==0) {
            return 2;            
        }
        return 1;
    }
    if(target<0) {
        return 1;
    }

    char& ret=cache[index][aNum][bNum][cNum][target];
    if(ret!=0) {
        return ret;        
    }
    
    if(getRet(index+1, aNum+1, bNum, cNum, target)==2) {
        retStr.push_back('A');
        return ret=2;
    }
    if(getRet(index+1, aNum, bNum+1, cNum, target-aNum)==2) {
        retStr.push_back('B');
        return ret=2;
    }
    if(getRet(index+1, aNum, bNum, cNum+1, target-aNum-bNum)==2) {
        retStr.push_back('C');
        return ret=2;
    }
    return ret=1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int target;
    cin>>strLen>>target;
    memset(cache, 0, sizeof(cache));
    if(getRet(0, 0, 0, 0, target)==1) {
        cout<<-1;
    }
    else {
        for(int i=retStr.size()-1; i>=0; i--) {
            cout<<retStr[i];
        }
    }
}
```
<br/>

>### 회고
>메모이제이션을 적극 활용하여 문제를 해결했다. 이 풀이가 맞는지 모르겠는데 우선 메모리의 크기가 너무 커 메모리 초과를 피하기 위해 char 배열을 사용하였다. 부분 문제의 수가 3억개 이상이기 때문에 시간 초과 가능성이 없진 않지만, 대부분의 부분 문제의 경우 계산을 할 필요가 없다. 예를 들어 문자열의 길이가 10일 경우 A의 개수, B의 개수, C의 개수의 합이 10 이하인 경우만 부분문제로 계산을 하게 된다. 이런 요소들을 고려했을 때 충분히 시간 안에 돌 것이라 판단하여 위와 같이 코드를 작성했다.