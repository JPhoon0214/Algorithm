숨바꼭질3
====
<br/>

>### 문제 유형/난이도
>골드5 / 0-1 BFS
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/13549">문제 바로 가기(baekjoon 13549)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int start, target;
    cin>>start>>target;
    deque<pair<int, int>> poses;
    poses.push_back({start, 0});
    vector<int> cache(1000000, 987654321);

    int ret=0;
    while(!poses.empty()) {
        int pos=poses.front().first;
        int times=poses.front().second;
        poses.pop_front();

        //처음부터 수빈이와 동생의 위치가 같은 경우
        if(pos==target)
            break;

        for(int i=0; i<3; i++) {
            int nextPos, nextTimes;
            if(i==0) {
                nextPos=pos*2;
                nextTimes=times;
            }
            else if(i==1) {
                nextPos=pos+1;
                nextTimes=times+1;
            }
            else {
                nextPos=pos-1;
                nextTimes=times+1;
            }

            if(nextPos<0 || (pos>target && i!=2))
                continue;
            
            if(cache[nextPos]<=nextTimes)
                continue;
            else
                cache[nextPos]=nextTimes;
            
            if(nextPos==target) {
                ret=nextTimes;
                break;
            }
            
            if(i==0) {
                poses.push_front({nextPos, nextTimes});
            }
            else {
                poses.push_back({nextPos, nextTimes});
            }
        }
    }
    cout<<ret;
}
```
<br/>

>### 회고
>다익스트라 등 다양한 방법으로 해결할 수 있는 문제 같지만, 나는 0-1 BFS에 관심이 생겨서 0-1BFS로 한번 풀어 봤다. 내가 0-1 BFS를 잘 구현했는지는 잘 모르겠다. 시간 복잡도가 더 큰 다익스트라로도 풀리는 문제이니 엉성하게 구현했더라도 이 문제는 통과할 수 있었을 것이다. 0-1 BFS는 그리 어려운 개념은 아니었지만, 그럼에도 앞으로 유용하게 사용할 수 있을 것 같은 느낌이 들었다. 조금 더 관련 개념을 공부해서 다른 문제에도 한번 적용해 봐야겠다.