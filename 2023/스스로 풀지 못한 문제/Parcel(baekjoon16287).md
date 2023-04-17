Parcel
====
<br/>

>### 문제 유형/난이도
>플레5 / DP
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/16287">문제 바로 가기(baekjoon 16287)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int target, n;
    cin>>target>>n;

    vector<int> inputs(n);
    for(int i=0; i<n; i++) {
        cin>>inputs[i];
    }
    sort(inputs.begin(), inputs.end());

    vector<bool> cache(1000000, false);

    bool isExist=false;    

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(inputs[i]+inputs[j]>=target)
                break;
            
            int currSum=inputs[i]+inputs[j];
            if(cache[target-currSum]) {
                isExist=true;
                break;
            }
        }

        for(int j=0; j<i; j++) {
            int availCase=inputs[j]+inputs[i];
            cache[availCase]=true;
        }
    }

    if(isExist) cout<<"YES";
    else cout<<"NO";
}
```
<br/>

>### 회고
>사실 풀 때는 막막했는데 어느정도 처음 생각한 아이디어가 근접했다고 볼 수는 있다.
>다만 나는 분할 정복과 비슷한 방식으로 최대 5000개의 입력 사이사이를 나누어 각각 왼쪽에서 2개 오른쪽에서 2개를 뽑아 조합하는 방식의 알고리즘을 고안했다. 하지만 사실 이렇게 하면 물론 연산 횟수는 줄어들 수 있겠지만, 여전히 n^4여서 시간 초과를 피할 수 없기 때문에 고민하다 답을 찾을 수 없어 인터넷에 검색을 해 보았다.
>만약 두개를 뽑아 가능한지 여부를 따져 본 이후에, 방금 뽑은 값을 포함해 만들 수 있는 모든 경우의 수를 cache에 추가해 둔다면, 숫자 두개를 뽑아 가능한지 따져보는데 n^2, 만들 수 있는 모든 경우의 수를 업데이트 하는데 n^2의 시간이 들게 되며 각각 별개로 계산되기 때문에 결국 n^2 시간 제한 안에 문제를 해결할 수 있게 된다.
>이번 문제는 내가 그동안 풀었던 DP 문제들과 조금 다르긴 했지만, 그래도 이런 문제도 술술 풀 수 있으면 좋겠다...