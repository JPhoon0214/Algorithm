우수마을
====
<br/>

>### 문제 유형/난이도
>골드2 / DP, 트리
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1949">문제 바로 가기(baekjoon 1949)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(10000, vector<int>(3, -1));

int getValue(int root, int state, vector<int>& value, vector<vector<int>>& linked, vector<bool> visited) {
    int& ret=cache[root][state];
    if(ret!=-1)
        return ret;

    ret=0;    
    visited[root]=true;
    
    if(state==0) {
        ret+=value[root];
        for(int i=0; i<linked[root].size(); i++) {
            int nextIndex=linked[root][i];
            if(visited[nextIndex])
                continue;
            ret+=getValue(nextIndex, 1, value, linked, visited);
        }
    }
    else if(state==1) {
        for(int i=0; i<linked[root].size(); i++) {
            int nextIndex=linked[root][i];
            if(visited[nextIndex])
                continue;
            ret+=max(getValue(nextIndex, 0, value, linked, visited), getValue(nextIndex, 2, value, linked, visited));
        }
    }
    else {
        for(int i=0; i<linked[root].size(); i++) {
            int tempRet=0;
            int mustPriority=linked[root][i];
            if(visited[mustPriority])
                continue;
            tempRet+=getValue(mustPriority, 0, value, linked, visited);
            for(int j=0; j<linked[root].size(); j++) {
                if(i==j)
                    continue;
                
                int nextIndex=linked[root][j];
                if(visited[nextIndex])
                    continue;
                tempRet+=max(getValue(nextIndex, 0, value, linked, visited), getValue(nextIndex, 2, value, linked, visited));           
            }
            ret=max(ret, tempRet);
        }
    }
    return ret;
}

int main() {
    int n;
    cin>>n;
    vector<int> value(n);
    vector<vector<int>> linked(n);
    vector<bool> visited(n, false);

    for(int i=0; i<n; i++) {
        cin>>value[i];
    }
    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin>>v1>>v2;
        linked[v1-1].push_back(v2-1);
        linked[v2-1].push_back(v1-1);
    }
    cout<<max(getValue(0, 0, value, linked, visited), getValue(0, 2, value, linked, visited));
}
```
<br/>

>### 회고
>지금의 내가 풀기에 조금 버거웠던 문제이다. 무엇보다 코드를 짜면서 나중에 내가 다시 봤을때 무슨 생각으로 코드를 짰는지 이해하기 어려울 것 같다는 생각에 마음이 아팠다... 일단 내가 생각한 아이디어는 다음과 같다
> >1. 루트가 우수마을일 경우(state 0) : 최대값은 자식 노드가 모두 우수마을이 아닌 경우의 합
> >2. 루트가 우수마을이 아니고 그 부모가 우수마을일 경우(state 1) : 최대값은 자식노드가 우수마을이거나 우수마을이 아닌 경우의 최대값의 합
> >3. 루트가 우수마을이 아니고 그 부모도 우수마을이 아닐 경우(state 2) : 2번의 경우와 동일하지만, 최소 한 개 이상의 자식 노드는 우수마을인 경우의 최대값
>
>더 나은 아이디어도 있을 것 같지만, 우선 나는 이 정도로도 문제를 해결하는데 문제는 없을것이라 생각해 이대로 코드를 짜봤다. 하지만 역시 마음에 드는 코드는 아닌 것 같다... 더 노력해서 세련된 코드를 짜고 싶다