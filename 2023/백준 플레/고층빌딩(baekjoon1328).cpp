#include <iostream>
#include <cstring>

using namespace std;

int calCase(int buildingNum, int leftSeen, int rightSeen, int cache[101][101][101]) {
    if(leftSeen==1 && rightSeen==1) {
        if(buildingNum==1) {
            return 1;
        }
        else {
            return 0;
        }        
    }
    if(buildingNum==0 || buildingNum+1<leftSeen+rightSeen) {
        return 0;
    }
    if(leftSeen<1 || rightSeen<1) {
        return 0;
    }

    int& ret=cache[buildingNum][leftSeen][rightSeen];
    if(ret!=-1) return ret;

    ret=0;


    ret=(ret+(long long)calCase(buildingNum-1, leftSeen-1, rightSeen, cache))%1000000007;
    ret=(ret+(long long)calCase(buildingNum-1, leftSeen, rightSeen-1, cache))%1000000007;
    ret=(ret+(long long)calCase(buildingNum-1, leftSeen, rightSeen, cache)*(buildingNum-2))%1000000007;

    return ret;
}

int main() {
    int buildingNum, leftSeen, rightSeen;
    cin>>buildingNum>>leftSeen>>rightSeen;

    int cache[101][101][101];
    memset(cache, -1, sizeof(cache));

    cout<<calCase(buildingNum, leftSeen, rightSeen, cache);
}