#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char cache[30][30][30][30][450];
vector<char> retStr;
int strLen;

int getRet(int index, int aNum, int bNum, int cNum, int target) {
    if(index==strLen) {
        if(target==0) {
            return 2;            
        }
        return 1;
    }
    if(target<0) {
        return 1;
    }

    char& ret=cache[index][aNum][bNum][cNum][target];
    if(ret!=0) {
        return ret;        
    }
    
    if(getRet(index+1, aNum+1, bNum, cNum, target)==2) {
        retStr.push_back('A');
        return ret=2;
    }
    if(getRet(index+1, aNum, bNum+1, cNum, target-aNum)==2) {
        retStr.push_back('B');
        return ret=2;
    }
    if(getRet(index+1, aNum, bNum, cNum+1, target-aNum-bNum)==2) {
        retStr.push_back('C');
        return ret=2;
    }
    return ret=1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int target;
    cin>>strLen>>target;
    memset(cache, 0, sizeof(cache));
    if(getRet(0, 0, 0, 0, target)==1) {
        cout<<-1;
    }
    else {
        for(int i=retStr.size()-1; i>=0; i--) {
            cout<<retStr[i];
        }
    }
}