멀티탭 스케줄링
====
<br/>

>### 문제 유형/난이도
>골드1 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1700">문제 바로 가기(baekjoon 1700)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int availUseOnce, dataNum;
    cin>>availUseOnce>>dataNum;
    vector<int> process(dataNum);
    for(int i=0; i<dataNum; i++) {
        cin>>process[i];
    }

    vector<int> nextProcessIndex(dataNum, 987654321);
    for(int i=0; i<dataNum; i++) {
        for(int j=i+1; j<dataNum; j++) {
            if(process[i]==process[j]) {
                nextProcessIndex[i]=j;
                break;
            }
        }
    }

    int ret=0;
    vector<int> working;
    for(int i=0; i<dataNum; i++) {
        bool isAlready=false;
        for(int j=0; j<working.size(); j++) {
            if(process[working[j]]==process[i]) {
                working[j]=i;
                isAlready=true;
                break;
            }
        }
        if(isAlready)
            continue;
        
        if(working.size()<availUseOnce) {
            working.push_back(i);
        }
        else {
            int maxData=-1;
            int maxIndex=-1;
            for(int j=0; j<working.size(); j++) {
                if(maxData<nextProcessIndex[working[j]]) {
                    maxData=nextProcessIndex[working[j]];
                    maxIndex=j;
                }
            }
            working[maxIndex]=i;    
            ret++;
        }
    }
    cout<<ret;
}
```
<br/>

>### 회고
>나에겐 쉽지 않은 문제였다... 6번 만에 성공했는데, 그 과정에서 코드가 많이 지저분해 지기도 했다. 그에 반해 기본적인 알고리즘은 어렵진 않은데, 멀티탭에 꼳혀 있는 플러그를 뽑아야 한다면, 가장 나중에 다시 사용하게 되는 플러그를 먼저 뽑는 방식으로 구현했다. 다만 구현 능력이 조금 부족해 예외 상황을 잘 처리하지 못한 것 같다. 위 아이디어는 제법 직관적이고 자명해 보이긴 하지만, 조금 더 고민해서 아이디어가 잘 맞아떨이진다는 것을 증명해 봐야 겠다.