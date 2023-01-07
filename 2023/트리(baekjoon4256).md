트리
====
<br/>

>### 문제 유형/난이도
>골드2 / 트리, 분할정복
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/4256">문제 바로 가기(baekjoon 4256)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPostOrder(queue<int>& preOrder, vector<int>& inOrder) {
    if(inOrder.empty())
        return;
    
    int standard=preOrder.front();
    preOrder.pop();
    
    vector<int> left, right;
    vector<int>::iterator iter=inOrder.begin();
    while(iter!=inOrder.end()) {
        if(*iter==standard) {
            iter++;
            break;            
        }
        left.push_back(*iter);
        iter++;
    }
    while(iter!=inOrder.end()) {
        right.push_back(*iter);
        iter++;
    }

    vector<int>().swap(inOrder);
    printPostOrder(preOrder, left);
    printPostOrder(preOrder, right);
    cout<<standard<<" ";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        int nodeNum;
        cin>>nodeNum;
        queue<int> preOrder;
        vector<int> inOrder(nodeNum);
        for(int i=0; i<nodeNum; i++) {
            int input;
            cin>>input;
            preOrder.push(input);
        }
        for(int i=0; i<nodeNum; i++) {
            cin>>inOrder[i];
        }
        printPostOrder(preOrder, inOrder);
        cout<<"\n";
    }
}
```
<br/>

>### 회고
>재귀함수에 조금만 익숙하다면, 쉽게 풀 수 있는 문제였다. 개인적인 생각으로는 난이도가 조금 높게 책정된 것 같다. 전위 순회를 할 경우 루트 노드가 가장 처음에 나오는 노드이므로 쉽게 알 수 있다. 이를 이용해 중위순회한 결과를 루트 노드의 왼쪽 서브트리와 오른쪽 서브트리로 구분해 재귀적으로 호출하고, 후위 순회를 해야 하므로 마지막에 루트를 출력하는 식으로 구현하였다. 저번 문제에서 벡터의 메모리 해제를 하지 않았다 메모리 초과가 났었기 때문에 이번엔 메모리 해제까지 철저히 구현하였다.