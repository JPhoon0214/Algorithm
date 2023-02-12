동전 뒤집기
====
<br/>

>### 문제 유형/난이도
>골드2 / 그리디 알고리즘
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1285">문제 바로 가기(baekjoon 1285)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int mapSize;

void upSideDown(vector<vector<int>>& map, int index) {
    for(int i=0; i<mapSize; i++) {
        map[index][i]++;
    }        
}

int getMin(vector<vector<int>>& map, int index) {
    if(index==mapSize) {
        int ret=0;
        for(int i=0; i<mapSize; i++) {
            int countUp=0;
            for(int j=0; j<mapSize; j++) {
                if(map[j][i]%2==0)
                    countUp++;
            }
            ret+=min(countUp, mapSize-countUp);
        }
        return ret;
    }
    
    int ret;
    ret=getMin(map, index+1);
    
    upSideDown(map, index);
    ret=min(getMin(map, index+1), ret);

    upSideDown(map, index);
    
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>mapSize;
    vector<vector<int>> map(mapSize, vector<int>(mapSize));
    for(int i=0; i<mapSize; i++) {
        string input;
        cin>>input;
        for(int j=0; j<mapSize; j++) {
            if(input[j]=='H') {
                map[i][j]=0;
            }
            else {
                map[i][j]=1;
            }
        }
    }
    cout<<getMin(map, 0);
} 
```
<br/>

>### 회고
>>한동안 spring 공부에 집중하느라 회고를 오랫동안 올리지 못했다.<br/>
>>코드가 아주 맘에 들지는 않지만, 풀이 과정이 꽤나 만족스러웠다. 우선 브루트포스로 풀어보려 했다. 행에 있는 동전을 뒤집는 경우, 열에 있는 동전을 뒤집는 경우, 둘다 뒤집는 경우, 아무것도 안 뒤집는 경우로 나누어 풀어보려 했지만, 이렇게 풀이할 경우 4^n개의 부분문제가 생기고, 각 부분문제마다 n의 시간 복잡도가 들기 때문에 O(4^n *n)의 시간 복잡도로 시간 초과가 날 것이라 생각했다. 고민하던 중 행 또는 열 둘 중 하나만 뒤집을지 뒤집지 않을지 결정하고 나면, 나머지 하나는 자동으로 결정된다는 것을 알게 되었다. 이를 이용해 O(2^n *n)으로 시간 복잡도를 크게 줄일 수 있었고, 시간 안에 풀 수 있었다.