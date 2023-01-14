이모티콘
====
<br/>

>### 문제 유형/난이도
>골드4 / BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/14226">문제 바로 가기(baekjoon 14226)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Emoticon {
    int screen;
    int clipBoard;
    int times;
};

int main() {
    int target;
    cin>>target;
    queue<Emoticon> emoticons;
    emoticons.push({1, 0, 0});
    vector<vector<bool>> visited(2000, vector<bool>(2000, false));
    
    int ret=0;    
    while(!emoticons.empty()) {
        if(ret!=0)
            break;
        int screen=emoticons.front().screen;
        int clipBoard=emoticons.front().clipBoard;
        int times=emoticons.front().times;
        emoticons.pop();

        for(int i=0; i<3; i++) {
            int nextScreen=screen, nextClipBoard=screen;
            if(i==0) {
                nextScreen=screen;
                nextClipBoard=screen;
            }
            else if(i==1) {
                nextScreen=screen+clipBoard;
                nextClipBoard=clipBoard;
            }
            else {
                nextScreen=screen-1;
                nextClipBoard=clipBoard;
            }
            if(nextScreen<0 || nextScreen>=2000 || nextClipBoard<0 || nextClipBoard>=2000)
                continue;
            if(visited[nextScreen][nextClipBoard])
                continue;
            if(nextScreen==target) {
                ret=times+1;
                break;
            }
            visited[nextScreen][nextClipBoard]=true;
            emoticons.push({nextScreen, nextClipBoard, times+1});
        }
    }
    cout<<ret;
}
```
<br/>

>### 회고
>전형적인 BFS문제였다. 그래프 알고리즘에 조금씩 익숙해지는 중인데, 그동안 막막했던 문제들이 뭔가 쉬워지는 느낌이다. 역시 스스로 고민해보는 시간도 중요하지만, 일단 남에게 배울 수 있는건 무조건 배워야 한다. 이 문제도 그래프 이론을 모를 때 낑낑댔던 기억이 있는데, 그래프이론을 조금만 공부하니 쉽게 풀 수 있었다.
>다만 처음에 switch-case문을 사용했을 때 메모리초과가 났었는데, 아무래도 switch-case를 자주 사용하지 않다 보니 익숙하지 않아 실수가 생겼던 것 같다. 일단 switch-case문을 공부해 보아야겠고, 앞으로 앵간하면 if문 위주로 사용해 익숙한 구조로 코딩을 반복해 실수를 줄여야 겠다.