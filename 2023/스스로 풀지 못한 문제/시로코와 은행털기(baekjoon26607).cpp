#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[80][81][16001];

int isAvail(vector<int>& strengths, int index, int toPick, int target) {
    if(index+1<toPick || target<0) {
        return 0;        
    }
    if(toPick==0) {
        return target==0;
    }
    if(index==0) {
        return target==strengths[index];
    }
    
    if(cache[index][toPick][target]!=-1) 
        return cache[index][toPick][target];
    
    int ret=max(isAvail(strengths, index-1, toPick, target), isAvail(strengths, index-1, toPick-1, target-strengths[index]));
    return cache[index][toPick][target]=ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, x;
    cin>>n>>k>>x;
    vector<int> strengths(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>strengths[i]>>temp;
    }
    memset(cache, -1, sizeof(cache));
    
    int ret=0;
    for(int i=0; i<=x*k; i++) {
        if(isAvail(strengths, n-1, k, i)) {
            ret=max(ret, i*(k*x-i));
        }
    }
    cout<<ret;
}
