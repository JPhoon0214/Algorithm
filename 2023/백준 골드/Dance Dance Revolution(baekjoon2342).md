Dance Dance Revolution
====
<br/>

>### 문제 유형/난이도
>골드3 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2342">문제 바로 가기(baekjoon 2342)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> cache(100000, vector<vector<int>>(5, vector<int>(5, -1)));
const int cost[5][5]={
    {1, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
};

int getMinCost(pair<int, int> pos, int index, vector<int>& instructions) {
    if(index==instructions.size())
        return 0;
    if(pos.first==pos.second)
        return 987654321;
    
    int& ret=cache[index][pos.first][pos.second];
    if(ret!=-1)
        return ret;

    int target=instructions[index];
    ret=min(getMinCost({target, pos.second}, index+1, instructions)+cost[pos.first][target], getMinCost({pos.first, target}, index+1, instructions)+cost[pos.second][target]);
    return ret;
}

int main() {
    vector<int> instructions;
    while(true) {
        int input;
        cin>>input;
        if(input==0)
            break;
        instructions.push_back(input);
    }
    cout<<getMinCost({0, instructions[0]}, 1, instructions)+2;
}
```
<br/>

>### 회고
>최근 DP 이론 공부를 열심히 하고 있어서, 백준 문제도 DP를 많이 풀어보려 한다
>이 문제를 풀이하기 위해 어떤 위치에서 다른 위치로 이동할 때 드는 비용을 전역 변수를 이용해 따로 정리해 놓았다. 또한 시작할 경우 두 발이 같은 위치에 있는데, 이는 이후 구현에 걸림돌이 되므로, 한발을 이동시킨 상태에서 시작하는 것으로 문제를 조금 변형하였다.