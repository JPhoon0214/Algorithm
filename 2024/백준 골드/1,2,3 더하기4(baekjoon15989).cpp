#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(10001, vector<int>(4, -1));

// bef: 이전에 선택한 숫자. 1, 2, 3 중 하나.
int getCaseNum(int input, int bef) {
    if(input<0) return 0;
    if(input==0) return 1;
    if(cache[input][bef]!=-1) return cache[input][bef];
 
    int ret=0;
    for(int i=1; i<=bef; i++) {
        ret+=getCaseNum(input-i, i);
    }

    return cache[input][bef]=ret;
}

int main() {
    int testCase;
    cin>>testCase;

    for(; testCase>0; testCase--) {
        int input;
        cin>>input;
        cout<<getCaseNum(input,3)<<"\n";
    }
}