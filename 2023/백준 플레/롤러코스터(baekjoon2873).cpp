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