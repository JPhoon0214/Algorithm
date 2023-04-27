우체국
====
<br/>

>### 문제 유형/난이도
>골드4 / 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2141">문제 바로 가기(baekjoon 2141)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin>>n;
    
    vector<long long> cache(n, 0);

    vector<pair<int, int>> infos(n);
    for(int i=0; i<n; i++) {
        cin>>infos[i].first>>infos[i].second;
    }
    sort(infos.begin(), infos.end());

    cache[0]=infos[0].second;
    for(int i=1; i<n; i++) {
        cache[i]=cache[i-1]+infos[i].second;
    }

    long long target=(cache[n-1]+1)/2;
    int left=0;
    int right=n-1;

    int index=lower_bound(cache.begin(), cache.end(), target)-cache.begin();
    cout<<infos[index].first;
}
```
<br/>

>### 회고
>이 문제에 직접적으로 적용되진 않지만 유명한 논리인데, n개의 정점이 일직선에 있을 때, 거리의 합이 최소가 되도록 하는 지점은 n개의 정점을 정렬했을 때 홀수 기준 가운데 인덱스의 정점이다. 이 문제에서도 아이디어는 비슷한데, 내가 어떤 점을 찍었을 때, 왼쪽에 있는 사람 숫자와 오른쪽에 있는 사람 숫자를 비교해 오른쪽 사람 숫자가 더 많다면 점을 오른쪽으로 이동시키는 것이 이득이고, 반대일 경우 왼쪽으로 이동시키는 것이 이득이다. 조금만 생각해보면 알 수 있는데, 예를 들어 어떤 점을 찍었을 때 그 점 오른쪽에 사람이 5명 왼쪽에 사람이 2명 있다면, 왼쪽으로 점을 1 이동시키면 거리의 합은 `-2+5=3` 즉 3이 늘어나는 반면, 오른쪽으로 1 이동시키면 `+2-5=-3`즉 3만큼 줄어든다. 따라서 어떤 점 기준 왼쪽에 사람이 얼마나 있는지 저장하는 배열 cache를 만든 후, 이분 탐색을 진행했다.