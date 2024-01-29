수 이어가기
====
<br/>

>### 문제 유형/난이도
>실버3 / 브루트포스
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/24725">문제 바로 가기(baekjoon 24725)</a>

<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

const int dxs[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int dys[8]={1, 1, 0, -1, -1, -1, 0, 1};

const string mbti[16]={
    "INFP", "INFJ", "INTP", "INTJ", "ISFP", "ISFJ", "ISTP", "ISTJ", 
    "ENFP", "ENFJ", "ENTP", "ENTJ", "ESFP", "ESFJ", "ESTP", "ESTJ"
};

int height, width;

bool isMBTI(string& curr) {
    for(int i=0; i<16; i++) {
        if(mbti[i]==curr) return true;
    }
    return false;
}

bool check(int x, int y, int dx, int dy, string& curr, vector<string>& map) {
    if(curr.size()==4) return isMBTI(curr);
    if(x<0 || x>width-1 || y<0 || y>height-1) return false;

    curr.push_back(map[y][x]);
    return check(x+dx, y+dy, dx, dy, curr, map);
}

int getCnt(vector<string>& map) {
    int cnt=0;

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            for(int k=0; k<8; k++) {
                string mbtiStr="";
                if(check(j, i, dxs[k], dys[k], mbtiStr, map)) cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin>>height>>width;

    vector<string> map(height);
    for(int i=0; i<height; i++) cin>>map[i];

    cout<<getCnt(map);
}
```
<br/>

>### 회고
>코드는 깔끔한 것 같다. 그런데 뭔가 3중 for문이 거슬리는...하하  
>dxs[], dys[]를 순회하는 반복문에서 범위를 8이 아니라 16으로 돌려서 두번 틀렸다. 요즘 이런 저런 실수로 한번에 잘 못맞추는데 감이 떨어진건가 싶다.  
>아니면 너무 새벽에 풀어서 제정신이 아닌 걸지도.  
>근데 다시 생각해보니 상수로 범위를 정한게 애초에 위험했던 것 같다. 향상된 for문이 아니면 size() 메서드를 다음부터 이용하자.  
>요즘 매일 한문제 이상씩은 풀고 있는데 자꾸 새벽에 풀다 보니 깃허브에 안올리고 자는 날이 많은 것 같다. 낮시간에 풀고 빨리 자는 걸로  
