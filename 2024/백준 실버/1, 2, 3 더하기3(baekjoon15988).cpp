#include <iostream>
#include <vector>

using namespace std;

vector<int> cache(1000001, -1);

int getCaseNum(int input) {
    if(input<0) return 0;
    if(input==0) return 1;
    if(cache[input]!=-1) return cache[input];

    cache[input]=0;
    for(int i=1; i<=3; i++) {
        cache[input]+=getCaseNum(input-i);
        cache[input]%=1000000009;
    }

    return cache[input];
}

int main() {
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        int input;
        cin>>input;
        cout<<getCaseNum(input)<<"\n";
    }
}