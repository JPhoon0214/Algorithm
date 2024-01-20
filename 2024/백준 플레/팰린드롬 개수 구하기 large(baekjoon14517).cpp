#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > cache(1000, vector<int>(1000, -1));

int getCaseNum(int left, int right, string& str) {
    if(cache[left][right]!=-1) return cache[left][right];
    if(left==right) return cache[left][right]=1;
    if(left+1==right) {
        if(str[left]==str[right]) return 3;
        return 2;
    }

    cache[left][right]=getCaseNum(left+1, right, str)+getCaseNum(left, right-1, str);
    cache[left][right]%=10007; 
    cache[left][right]+=10007;

    if(str[left]!=str[right]) {
        cache[left][right]-=getCaseNum(left+1, right-1, str);
    }
    else {
        cache[left][right]+=1;
    }

    cache[left][right]%=10007;

    return cache[left][right];
}

int main() {
    int ret=0;
    string str;
    cin>>str;

    cout<<getCaseNum(0, str.size()-1, str);
}