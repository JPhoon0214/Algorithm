컨닝
====
<br/>

>### 문제 유형/난이도
>플레4 / DP, 비트마스킹
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1014">문제 바로 가기(baekjoon 1014)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

int height, width;

int countStdNum(int bit) {
    int ret=0;
    while(bit!=0) {
        ret+=(bit%2);
        bit/=2;            
    }
    return ret;
}

void getNexts(vector<bool>& nextAvail, int bit, vector<string>& map, int index) {
    for(int i=0; i<height; i++) {
        if(map[i][index+1]=='x' || map[i][index+1]=='X')
            nextAvail[i]=false;
        
        if(bit%2==1) {
            for(int j=i-1; j<=i+1; j++) {
                if(j<0 || j>height-1)
                    continue;
                nextAvail[j]=false;
            }            
        }
        bit/=2;
    }
}

void makeBits(vector<bool>& nextAvail, vector<int>& nextBits, int index, int bit) {
    if(index==height) {
        nextBits.push_back(bit);
        return;
    }
    
    if(nextAvail[index]) {
        int sumBit=1<<index;
        makeBits(nextAvail, nextBits, index+1, bit|sumBit);
    }
    makeBits(nextAvail, nextBits, index+1, bit);
}

int maxAvailStdNum(int index, int bit, vector<string>& map, vector<vector<int>>& cache) {
    if(index==width)
        return countStdNum(bit);
    if(cache[index][bit]!=-1)
        return cache[index][bit];

    int& ret=cache[index][bit];
    
    vector<bool> nextAvail(height, true);
    getNexts(nextAvail, bit, map, index);

    vector<int> nextBits;
    makeBits(nextAvail, nextBits, 0, 0);

    ret=-1;
    for(int i=0; i<nextBits.size(); i++) {
        ret=max(ret, maxAvailStdNum(index+1, nextBits[i], map, cache)+countStdNum(bit));
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        cin>>height>>width;
        vector<string> map(height);
        vector<vector<int>> cache(width+1, vector<int>(1024, -1));
        
        //답을 한번에 구하기 위해 앞에 x 붙여줌
        for(int i=0; i<height; i++) {
            string input;
            cin>>input;
            map[i]="x"+input;
        }
        cout<<maxAvailStdNum(0, 0, map, cache)<<"\n";
    }
}
```
<br/>

>### 회고
>문제의 난이도가 높은 만큼 이틀동안 열심히 고민해서 해결했다. 그 과정에서 코드가 더러워지면 디버깅 하는게 거의 불가능해 질 것 같아서 최대한 천천히 생각하면서 되도록이면 깨끗하게 코드를 짜려 노력했다. 비트 마스킹을 이용한 DP로 풀었는데...다른 해결 방법은 사실 생각이 나지 않는다. 비트 마스킹을 이용하지 않으면 DP를 적용하기 위한 아이디어를 생각하기 어려울 것 같다. 아이디어는 한 열에 앉는 학생 모양이 정해지면, 그 이후 열의 학생들이 앉는 부분문제는 최적 부분 구조가 된다. 이를 이용해 한 열에 앉는 학생의 모양의 모든 경우의 수를 DP로 계산하여 해결하였다.
>
>조금 오래 고민하긴 했지만 나름 깔끔하게 문제를 해결한 것 같아 기분이 좋다. 아직 플레 문제는 푸는데 고민이 조금 필요한 것 같다...