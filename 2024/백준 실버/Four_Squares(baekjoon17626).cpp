#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXVALUE=987654321;

vector<int> cache(50001, -1);

int getMinSqNums(int input, int remain) {
    if(input<0) return MAXVALUE;
    if(cache[input]!=-1) return cache[input];
    if(remain==0) {
        if(input==0) return 0;
        else return MAXVALUE;
    }
    if(input==0) return 0;

    int sqrinput=(sqrt(input))+1;

    int& ret=cache[input];
    ret=MAXVALUE;
    for(int i=1; i<=sqrinput; i++) {
        ret=min(getMinSqNums(input-i*i, remain-1), ret);
    }
    ret+=1;
    return ret;
}

int main() {
    int input;
    cin>>input;

    cout<<getMinSqNums(input, 4);
}