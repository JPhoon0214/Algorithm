기업투자
====
<br/>

>### 문제 유형/난이도
>골드2 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2662">문제 바로 가기(baekjoon 2662)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int companyNum;
vector<vector<int>> cache(20, vector<int>(301, -1));

int getMax(vector<vector<int>>& value, int index, int money) {
    if(index==companyNum) {
        if(money==0) {
            return 0;
        }
        else {
            return -987654321;
        }
    }
    
    int& ret=cache[index][money];
    if(ret!=-1) {
        return ret;
    }

    int putMoney=-1;    
    for(int i=0; i<=money; i++) {
        int currRet=getMax(value, index+1, money-i)+value[index][i];
        if(ret<currRet) {
            ret=currRet;
            putMoney=i;            
        }
    }
    return ret;
}

void getAns(vector<vector<int>>& value, int index, int money, int target) {
    if(index+1==companyNum) {
        for(int i=0; i<=money; i++) {
            if(value[index][i]==target) {
                cout<<i;
                return;
            }
        }
    }
    
    for(int i=0; i<=money; i++) {
        if(cache[index+1][money-i]+value[index][i]==target) {
            cout<<i<<" ";
            getAns(value, index+1, money-i, target-value[index][i]);
            break;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int money;
    cin>>money>>companyNum;
    vector<vector<int>> value(companyNum, vector<int>(money+1, 0));
    for(int i=0; i<money; i++) {
        int currMoney;
        cin>>currMoney;
        for(int j=0; j<companyNum; j++) {
            cin>>value[j][currMoney];
        }
    }

    int ret=getMax(value, 0, money);
    cout<<ret<<"\n";
    getAns(value, 0, money, ret);
}
```
<br/>

>### 회고
>>오히려 체감 상 직전에 풀었던 난이도가 조금 더 높은 ABC 문제보다도 조금 더 어려웠던 것 같다. 어려웠던 이유는 ABC 문제의 경우 가능한지 가능하지 않은지만 판별하면 되었기 때문에 가능한 것이 확인되는 순간 해당 글자를 저장해 주면 되었지만, 이번 문제는 최적화 문제이기 때문에 그 상황에서 최적의 값을 찾았더라도, 그 상황이 되는 것 자체가 최고의 경우가 아닐 수 있기 때문에 최적일때 최적이도록 하는 요소들을 찾는 과정이 조금 더 복잡했다. 최적의 값을 찾을 때 재귀를 이용해 계산했기 때문에, 그때의 요소들을 찾는 과정도 재귀를 이용해 자연스럽게 찾도록 하였다.