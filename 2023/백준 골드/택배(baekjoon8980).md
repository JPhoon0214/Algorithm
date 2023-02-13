택배
====
<br/>

>### 문제 유형/난이도
>골드2 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/8980">문제 바로 가기(baekjoon 8980)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cityNum, capacity;

int ret=0;

void moveBoxes(int city, vector<pair<int, int>>& already, vector<vector<int>>& cityToCity) {
    if(city==cityNum) {
        return;
    }
    
    while(!already.empty()) {
        pair<int, int> curr=already.back();
        if(curr.first==city) {
            ret+=curr.second;
            already.pop_back();
        }
        else {
            break;
        }
    }

    vector<pair<int, int>> newContainer;
    int remainCapacity=capacity;
    int cityPointer=city+1;
    while(remainCapacity>0) {        
        if(already.empty() || already.back().first>cityPointer) {
            int moveBox=remainCapacity>=cityToCity[city][cityPointer] ? cityToCity[city][cityPointer] : remainCapacity;
            
            if(moveBox>0)
                newContainer.push_back({cityPointer, moveBox});
            
            remainCapacity-=moveBox;
            cityPointer++;
        }
        else {
            pair<int, int> curr=already.back();
            int moveBox=remainCapacity>=curr.second ? curr.second : remainCapacity;
            
            if(moveBox>0)
                newContainer.push_back({curr.first, moveBox});
            
            remainCapacity-=moveBox;
            already.pop_back();
        }
    }
    
    already=newContainer;
    reverse(already.begin(), already.end());

    moveBoxes(city+1, already, cityToCity);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>cityNum>>capacity;
    vector<vector<int>> cityToCity(cityNum, vector<int>(cityNum, 0));
        
    int infoNum;
    cin>>infoNum;
    for(int i=0; i<infoNum; i++) {
        int start, end, amount;
        cin>>start>>end>>amount;
        cityToCity[start-1][end-1]=amount;
    }    

    vector<pair<int, int>> already;
    moveBoxes(0, already, cityToCity);
    cout<<ret;
}
```
<br/>

>### 회고
>구현을 잘 하지 못했다. 아이디어는 간단했지만 구현 능력 부족으로 reverse함수를 사용하게 되었다. 다음부터 조금 더 꼼꼼히 설계한 후 문제를 풀어 이런 일이 없도록 해야겠다.