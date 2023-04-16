#include <iostream>
#include <cstring>

using namespace std;

int cache[1000001];

/*
int calCaseNum(int width) {
    if(width<=0) {
        return 1;
    }
    else if(width==1) {
        return 2;
    }
    else if(width==2) {
        return 7;
    }
    
    int& ret=cache[width];
    if(ret!=-1) {
        return ret;
    }

    //ret=((long long)calCaseNum(width-1)*3+(long long)calCaseNum(width-2)-(long long)calCaseNum(width-3))%1000000007;
    ret=((long long)calCaseNum(width-10)*3)%1000000007;
    
    return ret;
}
*/

int main() {
    int width;
    cin>>width;

    memset(cache, -1, sizeof(cache));

    for(int i=0; i<=width; i++) {
        if(i==0) cache[i]=1;
        else if(i==1) cache[i]=2;
        else if(i==2) cache[i]=7;
        else {
            cache[i]=((long long)cache[i-1]*3+cache[i-2]-cache[i-3])%1000000007;
            cache[i]=cache[i]>=0 ? cache[i] : cache[i]+1000000007;
        }        
    }

    cout<<cache[width];
}