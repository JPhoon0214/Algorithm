습격자 초라기
====
<br/>

>### 문제 유형/난이도
>플레3 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/1006">문제 바로 가기(baekjoon 1006)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

//type 0:완전 네모 1:위가 삐져나온 네모 2:아래가 삐져나온 네모
int getCaseNum(vector<vector<int>>& cache, vector<vector<int>>& cost, int index, int width, int type, int availCover) {
    if(index==width-1) {
        if(type==0) {
            if(cost[index][0]+cost[index][1]<=availCover) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else {
            return 1;
        }
    }
    if(index==width) {
        return 0;
    }
    
    int& ret=cache[index][type];
    if(ret!=-1) {
        return ret;
    }
    
    ret=987654321;
    if(type==0) {
        if(cost[index][0]+cost[index+1][0]<=availCover || cost[index][1]+cost[index+1][1]<=availCover) {
            if(cost[index][0]+cost[index+1][0]<=availCover && cost[index][1]+cost[index+1][1]<=availCover) {
                ret=min(ret, 2+getCaseNum(cache, cost, index+2, width, 0, availCover));
            }
            if(cost[index][0]+cost[index+1][0]<=availCover) {
                ret=min(ret, 2+getCaseNum(cache, cost, index+1, width, 2, availCover));
            }
            if(cost[index][1]+cost[index+1][1]<=availCover) {
                ret=min(ret, 2+getCaseNum(cache, cost, index+1, width, 1, availCover));
            }
        }
        if(cost[index][0]+cost[index][1]<=availCover) {
            ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 0, availCover));
        }
        else {
            ret=min(ret, 2+getCaseNum(cache, cost, index+1, width, 0, availCover));
        }
    }
    else if(type==1) {
        if(cost[index][0]+cost[index+1][0]<=availCover) {
            ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 2, availCover));
        }
        ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 0, availCover));
    }
    else {
        if(cost[index][1]+cost[index+1][1]<=availCover) {
            ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 1, availCover));
        }
        ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 0, availCover));
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
        int width, availCover;
        cin>>width>>availCover;
        vector<vector<int>> cost(width, vector<int>(2));
        for(int i=0; i<width; i++) {
            cin>>cost[i][0];
        }
        for(int i=0; i<width; i++) {
            cin>>cost[i][1];
        }
        
        vector<vector<int>> cache(10000, vector<int>(3, -1));
        int ret=getCaseNum(cache, cost, 0, width, 0, availCover);

        if(width>1 && (cost[0][0]+cost[width-1][0]<=availCover || cost[0][1]+cost[width-1][1]<=availCover)) {
            if(cost[0][0]+cost[width-1][0]<=availCover && cost[0][1]+cost[width-1][1]<=availCover) {
                int tempCost[2][2];
                tempCost[0][0]=cost[0][0]; tempCost[1][0]=cost[width-1][0];
                tempCost[0][1]=cost[0][1]; tempCost[1][1]=cost[width-1][1];
                cost[0][0]=cost[0][1]=cost[width-1][0]=cost[width-1][1]=availCover;
                
                cache=vector<vector<int>>(10000, vector<int>(3, -1));
                ret=min(ret, getCaseNum(cache, cost, 0, width, 0, availCover)-2);
                
                cost[0][0]=tempCost[0][0]; cost[width-1][0]=tempCost[1][0];
                cost[0][1]=tempCost[0][1]; cost[width-1][1]=tempCost[1][1];
            }
            if(cost[0][0]+cost[width-1][0]<=availCover) {
                int tempCost[2];
                tempCost[0]=cost[0][0]; tempCost[1]=cost[width-1][0];
                cost[0][0]=cost[width-1][0]=availCover;

                cache=vector<vector<int>>(10000, vector<int>(3, -1));
                ret=min(ret, getCaseNum(cache, cost, 0, width, 0, availCover)-1);

                cost[0][0]=tempCost[0]; cost[width-1][0]=tempCost[1];
            }
            if(cost[0][1]+cost[width-1][1]<=availCover) {
                int tempCost[2];
                tempCost[0]=cost[0][1]; tempCost[1]=cost[width-1][1];
                cost[0][1]=cost[width-1][1]=availCover;

                cache=vector<vector<int>>(10000, vector<int>(3, -1));

                ret=min(ret, getCaseNum(cache, cost, 0, width, 0, availCover)-1);

                cost[0][1]=tempCost[0]; cost[width-1][1]=tempCost[1];
            }
        }
        cout<<ret<<"\n";
    }
}
```
<br/>

>### 회고
>코드의 길이가 짧다고 좋은 코드가 되는 것은 아니지만, 코드가 길어질수록 실수를 하기도 쉽고, 오류를 찾기도 힘들어지는 것 같다. 특히 짧은 시간에 정확한 코드를 짜야 하는 알고리즘 문제에서 코드가 길어지는 것은 되도록 피하고 싶다. 이번 문제는 코드가 많이 길어진 것 같다.
>예전에 2*n크기의 타일 채우기 문제에서 힌트를 얻어 풀 수 있었다. 이 문제가 곤란한 이유는 원으로 되어 있기 때문인데, 이를 직선으로 생각해 우선 계산하고, 직선의 처음과 끝이 연결되는 경우만 따로 따져준다면 타일링 문제와 비슷하게 풀 수 있을 것이라 생각했다. 그렇게 생각하고 도전했는데, 생각보다 많이 어려웠다.
>우선 완전한 네모 모양, ㄱ모양 ㅢ모양의 구역이 남은 경우의 최소 투입할 수 있는 부대의 수를 저장하는 cache[width][3]을 정의했다. 이때 각각의 모양에서 이런 저런 상황을 종이에 그려가면서 모든 경우를 파악하고, 이를 코드로 옮겨 적었다. 처음과 끝이 연결된 경우는 이미 짜논 함수를 재사용하고 싶었기 때문에, 서로 연결하고자 하는 부분에 한 부대의 전체 인원수를 대입한 상태로 함수에 넘겨주었다. 이렇게 되면 사실상 연결하고자 하는 부분에 있는 구역에는 딱 한개의 부대만이 투입될 수 있기 때문에, 이후에 간단히 1혹은 2를 빼주면 되었다.
>
>역시 내가 풀기에 조금 버거운 문제였던 것 같다. 푸는데 2일이 걸렸지만, 그래도 누구의 도움도 받지 않고, 어떻게든 풀어내어 기분은 좋다.