알파벳

### 문제 유형/난이도
>골드4 / DFS  

>### 문제
> <a href="https://www.acmicpc.net/problem/1987">문제 바로 가기(baekjoon 1987)</a>  

>### 코드
```c++
#include <iostream>
#include <vector>

using namespace std;

const int dy[4]={1, 0, -1, 0};
const int dx[4]={0, 1, 0, -1};

int width, height;

int getMaxSpace(int x, int y, vector<string>& map, vector<bool>& visited) {
    if(x<0 || x>width-1 || y<0 || y>height-1) return 0;
    if(visited[map[y][x]-'A']) return 0;

    visited[map[y][x]-'A']=true;
    int ret=0;
    for(int i=0; i<4; i++) {
        ret=max(ret, 1+getMaxSpace(x+dx[i], y+dy[i], map, visited));
    }
    visited[map[y][x]-'A']=false;
    return ret;
}

int main() {
    cin>>height>>width;
    vector<string> map(height);
    for(int i=0; i<height; i++) cin>>map[i];

    vector<bool> visited('Z'-'A'+1, false);

    cout<<getMaxSpace(0, 0, map, visited);
}
```
<br/>

>### 회고
>내일 수업때 그래프 이론 하려고 풀어보려 했는데 DFS를 이용해야 하는 문제여서 약간 망설여졌다. 다른 문제를 찾아봤는데 마땅한 문제가 없어서 어쩔수 없이 DFS정도만 같이 알려줘야 할 것 같다. 두번째 문제는 이 문제가 순수 그래프가 아닌 유사 그래프를 이용해 푸는 문제라는 점이다. 꾸역꾸역 구조체를 만들고 그래프 구조를 만들어 풀어봤는데 시간 초과가 났다(...) 그냥 이런 문제도 자주 나오니 유사 그래프 문제 푸는 방법도 알려줘야겠다.  
