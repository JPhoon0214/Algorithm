롤러코스터
====
<br/>

>### 문제 유형/난이도
>플레3 / 구현, 구성적, 그리디
<br/>

>### 문제
> <a href="https://www.acmicpc.net/problem/2873">문제 바로 가기(baekjoon 2873)</a>
<br/>

>### 코드
```C++
#include <iostream>
#include <vector>

using namespace std;

void printHorizontal(int row, int column) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            if(j==column-1) {
                if(i!=row-1) {
                    cout<<'D';                  
                }
                continue;
            }

            if(i%2==0) {
                cout<<'R';
            }
            else {
                cout<<'L';
            }
        }
    }
}

void printVertical(int row, int column) {
    for(int i=0; i<column; i++) {
        for(int j=0; j<row; j++) {
            if(j==row-1) {
                if(i!=column-1) {
                    cout<<'R';
                }
                continue;
            }

            if(i%2==0) {
                cout<<'D';
            }
            else {
                cout<<'U';
            }
        }
    }
}

int main() {
    int row, column;
    cin>>row>>column;

    int minX, minY;
    int minValue=987654321;
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            int input;
            cin>>input;
            
            if(i%2==0 && j%2==0) {
                continue;
            }
            if(i%2==1 && j%2==1) {
                continue;
            }
            
            if(input<minValue) {
                minX=j; minY=i;
                minValue=input;
            }
        }
    }

    if(row%2==1) {
        printHorizontal(row, column);
    }
    else if(column%2==1) {
        printVertical(row, column);
    }
    else {
        int verIndex=0;
        int horIndex=0;
        // 왼쪽->오른쪽->왼쪽(최소값 나오기 이전)
        for(; verIndex<minY-1; verIndex+=2) {
            printHorizontal(2, column);
            cout<<'D';
        }

        // 최소값과 같은 y값, 최소값 이전 X값
        for(; horIndex<minX-1; horIndex+=2) {
            printVertical(2, 2);
            cout<<'R';
        }

        // 최소 좌표 처리
        if(minX<column-2) {
            if(minY%2==0) {
                cout<<"DRRUR";
            }
            else {
                cout<<"RDRUR";
            }            
        }
        else {
            if(minY%2==0) {
                cout<<"DR";
            }
            else {
                cout<<"RD";
            }   
        }

        // 최소값과 같은 y값, 최소값 이후 X값
        for(horIndex+=3; horIndex<column-2; horIndex+=2) {
            printVertical(2, 2);
            cout<<'R';
        }
        if(minX<column-2) {
            cout<<'D';
        }
        //최소값이 있는 y가 마지막 y가 아닐 경우
        if(minY<row-2) {
            cout<<'D';
            // 오른쪽 -> 왼쪽(최소값 나온 후)
            for(int i=0; i<column; i++) {
                if(i==column-1) {
                    cout<<'D';
                }
                else {
                    cout<<'L';
                }
            }
            // 왼쪽 -> 오른쪽(최소값 나온 후)
            for(verIndex+=3; verIndex<row-2; verIndex+=2) {            
                printHorizontal(2, column);
                cout<<'D';
            }
    
            //마지막줄
            for(int i=0; i<column-1; i++) {
                cout<<"R";
            }
        }        
    }
}
```
<br/>

>### 회고
>이 문제는 아이디어도 조금은 긴가민가했다. 여러 케이스를 손으로 그려보면서 여러가지를 알아낼 수 있었다.
>>    1. 행과 열 중 하나라도 홀수일 경우 모든 칸을 방문할 수 있다.
>>    2. 그렇지 못할 경우 최소 한개의 칸을 방문하지 않음으로서 종착지에 도달할 수 있다. 이때 방문하지 않는 칸은 짝수번째 행일 경우 짝수번째 칸, 홀수번째 행일 경우 홀수번째 칸이어야 한다. 물론 그렇지 않은 칸을 방문하지 않을 수도 있는데, 이럴 경우 위에 언급한 조건의 칸을 최소 1개 이상 방문할 수 없게 되기 때문에 문제에서 요구하는 가장 큰 기쁨을 얻기 위해서는 위 조건을 칸 1개를 방문하지 않아야 한다.
>손으로 이것저것 그려보면서 위 가정이 틀리는 반례는 찾지 못했지만, 조금 긴가민가하는 마음으로 구현을 시작했다. 하지만 구현 역시 쉽지 않았다. 그동안 여러 알고리즘 개념 집중하느라 구성적 알고리즘 해결 능력을 기르지 못한 탓도 있었다. 시행착오끝에 조금 지저분하지만 아이디어를 완전히 구현하였다.