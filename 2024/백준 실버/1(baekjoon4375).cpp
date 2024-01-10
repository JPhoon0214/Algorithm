#include <iostream>

using namespace std;

int main() {
    while(true) {
        int input;
        cin>>input;

        if(cin.eof()) break;

        int cnt=0;
        int currRemain=0;
        while(true) {
            cnt++;
            currRemain*=10;
            currRemain+=1;
            currRemain%=input;
            if(currRemain==0) break;
        }
        cout<<cnt<<"\n";
    }
}