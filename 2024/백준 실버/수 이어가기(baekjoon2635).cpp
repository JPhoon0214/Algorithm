#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input;
    cin>>input;

    int maxCnt=-1;
    int maxAft=-1;
    for(int i=1; i<=input; i++) {
        int currCnt=2;
        int bef=input, aft=i;
        while(true) {
            int temp=aft;
            aft=bef-aft;
            bef=temp;

            if(aft<0) break;

            currCnt++;
        }
        if(maxCnt<currCnt) {
            maxCnt=currCnt;
            maxAft=i;
        }
    }

    cout<<maxCnt<<"\n";

    int bef=input, aft=maxAft;
    cout<<bef<<" "<<aft<<" ";
    while(true) {
        int temp=aft;
        aft=bef-aft;
        bef=temp;

        if(aft<0) break;

        cout<<aft<<" ";
    }
}