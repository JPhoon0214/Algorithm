#include <iostream>
#include <vector>

using namespace std;

vector<int> cache(100001, -1);

int getAvailCase(int num) {
    if(num<0) return 0;
    if(num==0) return 1;
    if(cache[num]!=-1) return cache[num];

    int ret=0;
    for(int i=1; i<=3; i++) {
        ret+=getAvailCase(num-i);
        ret%=1000000009;
    }

    return cache[num]=ret;
}

int main() {
    int testCase;
    cin>>testCase;

    for(testCase; testCase>0; testCase--) {
        int input;
        cin>>input;

        int ret=0;
        for(int mid=input%2; mid<=(input%2)+2; mid+=2) {
            ret+=getAvailCase((input-mid)/2);
            ret%=1000000009;
        }
        cout<<ret<<"\n";
    }
}