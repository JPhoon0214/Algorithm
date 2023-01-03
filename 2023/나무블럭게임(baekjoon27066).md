나무블럭게임
====
<br/>

>### 문제 유형/난이도
>골드5 / 그리디 알고리즘
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/27066">문제 바로 가기(baekjoon 27066)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int sumAll=0;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
        sumAll+=nums[i];
    }
    sort(nums.begin(), nums.end());
    
    double ret=n>1 ? nums[n-2] : nums[0];
    ret=max((double)ret, (double)sumAll/n);

    cout<<fixed;
    cout.precision(10);
    cout<<ret;
}
```
<br/>

>### 회고
>>GoodBye Boj 2022에 참가해 푼 문제다.
>>나무 블럭을 점수 크기 순으로 나열했을 때, 나무 블럭이 한개가 되지 않는 이상 마지막 나무 블럭은 선택될 수 없고, 그 이외의 나무 블럭은 무엇이든 선택될 수 있다.
>>따라서 단일 블럭이 선택될 때 가장 큰 점수를 얻기 위해선 마지막에서 두번째 블럭을 선택해야 한다.
>>나무 블럭을 서로 합치는 경우도 고려해야 하는데, 단일 블럭을 선택할 때 가장 큰 n-1번째 블럭보다 큰 블럭을 만들기 위해 n번째 블럭과 n-2번째 블럭의 평균을 구할 경우, 이 평균이 n-1번째 블록의 점수보다 크다면 n-1번째 블럭은 여전히 뒤에서 두번째 블럭이므로 선택될 수 있고, 이 평균이 n-1번째 블록의 점수보다 작다면 n번째 블록과 n-2번째 블록 점수의 평균이 선택될 수는 있지만 앞서 단일 블록으로 선택한 n-1번째 블록의 점수보다 낮은 점수를 얻게 된다.
>>모든 블록을 더해 하나의 블록으로 만들 경우, 가장 마지막 블록을 선택할 수 있게 되기 때문에 앞서 말한 상황의 예외 케이스가 발생한다.
>>따라서 블록의 점수를 크기 순으로 정렬했을 때 n-1번째 블록의 점수와, 모든 블록의 점수의 평균 중 큰 값이 정답이 된다.<br/>
    
>>이 문제를 푸는데 한시간은 걸린 것 같은데, 다른 잘 푸는 분들은 5분 10분만에도 풀어서 신기했다.