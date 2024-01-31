체커

>### 문제 유형/난이도
>플레4 / 브루트포스

>### 문제
> <a href="https://www.acmicpc.net/problem/1090">문제 바로 가기(baekjoon 1090)</a>  

>### 코드
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

void getDisToCurrDot(int targetY, int targetX, vector<pair<int, int> >& dots, vector<int>& storeDis) {
    for(int i=0; i<dots.size(); i++) {
        int ret=abs(targetY-dots[i].second)+abs(targetX-dots[i].first);
        storeDis.push_back(ret);
    }
}

void getDis(vector<pair<int, int> >& dots, vector<vector<vector<int> > >& shortestLen) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            getDisToCurrDot(dots[i].second, dots[j].first, dots, shortestLen[i][j]);
            sort(shortestLen[i][j].begin(), shortestLen[i][j].end());
        }
    }
}

int getRet(vector<vector<vector<int> > >& shortestLen, int toSelect) {
    int totalRet=987654321;
    int targetx, targety;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int ret=0;
            for(int selected=0; selected<toSelect; selected++) {
                ret+=shortestLen[i][j][selected];
            }
            if(totalRet>ret) {
                totalRet=ret;
            }
            totalRet=min(totalRet, ret);
        }
    }
    return totalRet;
}

int main() {
    cin>>n;
    vector<vector<vector<int> > > shortestLen(n, vector<vector<int> >(n));

    vector<pair<int, int> > dots(n);
    for(int i=0; i<n; i++) cin>>dots[i].first>>dots[i].second;

    getDis(dots, shortestLen);

    for(int i=0; i<n; i++) {
        cout<<getRet(shortestLen, i+1)<<" ";
    }    
}
```  

>### 회고
오늘은 간만에 플레 문제를 하나 풀었다. 사실 고민은 이틀전 지하철 타고 본가 내려오면서 용우가 같이 풀어보자 해서 그때 했었고, 이틀전에 핵심적인 아이디어들은 모두 생각해 오늘은 구현만 했다. 우선 체커들이 주어졌을 때 이 체커들이 모여 하는 위치는 한번에 알 수 있다. 1차원에서 체커가 n개 놓여 있다고 생각하고, 이 체커들이 모여아 하는 점을 임의로 잡는다. 만일 임의로 잡은 점을 왼쪽으로 1만큼 옮겼을 때 체커들이 움직여야 하는 거리는 이전에 임의로 잡았던 점까지 모이는데 필요한 거리에 비해 왼쪽 체커들의 개수만큼 가까워 질 것 이고, 오른쪽 체커의 개수만큼 멀어질 것이다. 따라서 임의로 잡은 점 왼쪽에 체커가 더 많다면 왼쪽으로 옮기는게 유리하고, 오른쪽에 더 많다면 오른쪽으로 옮기는 것이 유리하다. 결과적으로 체커의 개수가 홀수라면 좌표 순서대로 정렬했을 때 가운데 체커의 좌표로 움직이는 것이 최소 거리고, 짝수라면 가운데 두 체커 사이의 아무 점으로 움직이면 된다. 용우가 이미 체커가 있는 x좌표 혹은 y좌표로 움직이는 것이 최단 거리를 보장한다는 것을 활용해 브루트 포스로 풀자고 하였고 그렇게 풀었다. 처음 아이디어는 내가 냈지만, 푸는 과정에서 용우 도움을 받아서 그런지 뭔가 찜찜하다.  
