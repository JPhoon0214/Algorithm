#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache(1001, vector<long long>(1001, -1));
int totalColor, totalToPick;

long long getRet(int remainNum, int toPick) {
    if(toPick==0)
        return 1;
    if(remainNum<toPick)
        return 0;
    
    if(cache[remainNum][toPick]!=-1)
        return cache[remainNum][toPick];

    long long ret=0;
    for(int i=remainNum; i>0; i--) {
        int nextRemain=i-2;
        ret+=getRet(nextRemain, toPick-1);
        ret%=1000000003;
    }
    return cache[remainNum][toPick]=ret;
}

int main() {
    cin>>totalColor>>totalToPick;
    long long ret=getRet(totalColor-3, totalToPick-1);
    for(int i=1; i<totalColor; i++) {
        ret+=getRet(totalColor-i-2, totalToPick-1);
        ret%=1000000003;
    }
    cout<<ret;
}