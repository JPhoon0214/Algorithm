#include <iostream>
#include <vector>

using namespace std;

int height, width;

vector<vector<int>> cache(20, vector<int>(40000, -1));

void makeAllCase(vector<int>& cases, int bit, int ret, int index) {
    if(index==height) {
        cases.push_back(ret);
        return;
    }    
    if(bit%2==1) {
        makeAllCase(cases, bit/2, ret, index+1);
    }
    else {
        int tempBit=1<<index;
        makeAllCase(cases, bit/2, ret+tempBit, index+1);
        bit/=2;
        if(bit%2==0 && index+1<height) {
            makeAllCase(cases, bit/2, ret, index+2);
        }
    }
}

int getCase(int level, int bit) {
    if(level<0) {
        if(bit==0) {
            return 1;
        }
        return 0;
    }

    int& ret=cache[level][bit];
    if(ret!=-1) {
        return ret;
    }

    ret=0;    
    vector<int> cases;
    makeAllCase(cases, bit, 0, 0);
    for(int i=0; i<cases.size(); i++) {
        ret+=getCase(level-1, cases[i]);
        ret%=9901;
    }
    return ret;
}

int main() {
    cin>>height>>width;
    cout<<getCase(width-1, 0);
}