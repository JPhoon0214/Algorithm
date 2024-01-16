#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > cache(100001, vector<int>(4, -1));

int getCase(int n, int bef) {
    if(n<0) return 0;
    if(n==0) return 1;
    if(cache[n][bef]!=-1) return cache[n][bef];

    int ret=0;
    for(int i=1; i<=3; i++) {
        if(bef==i) continue;
        ret+=getCase(n-i, i);
        ret%=1000000009;
    }

    return cache[n][bef]=ret;
}

int main() {
    int testCase;
    cin>>testCase;
    
    for(testCase; testCase>0; testCase--) {
        int n;
        cin>>n;
        cout<<getCase(n, 0)<<"\n";
    }
}