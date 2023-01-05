이진검색트리
====
<br/>

>### 문제 유형/난이도
>골드5 / 그래프, 트리, 재귀
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/5639">문제 바로 가기(baekjoon 5639)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

void makeRet(vector<int>& nodes, vector<int>& ret) {
    if(nodes.empty())
        return;

    int standard=nodes[0];
    vector<int> lessNodes;
    vector<int> greaterNodes;
    for(int index=1; index<nodes.size(); index++) {
        int curr=nodes[index];
        if(curr<standard) {
            lessNodes.push_back(curr);
        }
        else {
            greaterNodes.push_back(curr);
        }
    }
    vector<int>().swap(nodes);
    ret.push_back(standard);
    makeRet(greaterNodes, ret);
    makeRet(lessNodes, ret);
}

int main() {
    vector<int> nodes;
    vector<int> ret;

    while(true) {
        int input;
        cin>>input;
        if(cin.eof()) {
            break;
        }
        nodes.push_back(input);
    }    
    makeRet(nodes, ret);
    while(!ret.empty()) {
        cout<<ret.back()<<"\n";
        ret.pop_back();
    }
}
```
<br/>

>### 회고
>처음에 어떻게 풀지 고민을 잘 해보면 쉽게 풀 수 있는 문제였던 것 같다.
>가장 단순히 문제를 푸는 방법은 전위 순회 결과를 보고 그래프를 직접 구현해 보는 것이다.
>충분히 가능한 방법이지만, 더 쉬운 방법은 전위 수회 결과를 보고 바로 후위 순회 결과를 도출하는 것이다.
>결과 벡터는 뒤에서부터 읽을 때 후위 순회 결과를 반환하도록 만든다고 하면, 입력으로 주어진 숫자 중 첫번째 숫자가 노드이므로, 우선 결과 벡터에 추가하고, 노드보다 작은 숫자들, 큰 숫자들을 따로 묶어 왼쪽 서브 트리, 오른쪽 서브 트리를 분리한다. 이후 재귀 함수를 이용해 오른쪽 서브 트리->왼쪽 서브 트리 순서로 재귀 호출 인자로 넘겨주면 앞서 말한 과정을 반복해 결과 벡터에는 뒤에서부터 읽을 경우 후위 순회 결과가 되도록 노드들이 저장된다.
>주의할 점은 메모리를 관리해야 한다는 점이다. 왠지 메모리가 초과될 것 같았지만 메모리 해제 없이 제출해 봤는데 역시 메모리 초과가 발생했다. 재귀 호출의 경우 최대 400메가 정도의 메모리가 벡터로 인해 할당될 수 있기 때문에, 안쓰게 된 벡터는 메모리 해제를 하던지 재귀 함수의 구조를 조금 바꿔야 한다.
>c++에서 벡터의 메모리를 해제할 방법을 딱히 찾지 못해 임시 벡터를 생성해 기존 벡터가 임시로 생성된 빈 벡터를 가리키게 하고, 기존 벡터가 가리키던 메모리 공간은 더 이상 가리키는 포인터가 없어 해제되도록 하였다.
>벡터 컨테이너의 메모리 해제를 하는 더 나은 방법이 있을까??