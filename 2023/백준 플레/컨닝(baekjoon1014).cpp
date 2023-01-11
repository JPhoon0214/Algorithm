#include <iostream>
#include <vector>

using namespace std;

int height, width;

int countStdNum(int bit) {
    int ret=0;
    while(bit!=0) {
        ret+=(bit%2);
        bit/=2;            
    }
    return ret;
}

void getNexts(vector<bool>& nextAvail, int bit, vector<string>& map, int index) {
    for(int i=0; i<height; i++) {
        if(map[i][index+1]=='x' || map[i][index+1]=='X')
            nextAvail[i]=false;
        
        if(bit%2==1) {
            for(int j=i-1; j<=i+1; j++) {
                if(j<0 || j>height-1)
                    continue;
                nextAvail[j]=false;
            }            
        }
        bit/=2;
    }
}

void makeBits(vector<bool>& nextAvail, vector<int>& nextBits, int index, int bit) {
    if(index==height) {
        nextBits.push_back(bit);
        return;
    }
    
    if(nextAvail[index]) {
        int sumBit=1<<index;
        makeBits(nextAvail, nextBits, index+1, bit|sumBit);
    }
    makeBits(nextAvail, nextBits, index+1, bit);
}

int maxAvailStdNum(int index, int bit, vector<string>& map, vector<vector<int>>& cache) {
    if(index==width)
        return countStdNum(bit);
    if(cache[index][bit]!=-1)
        return cache[index][bit];

    int& ret=cache[index][bit];
    
    vector<bool> nextAvail(height, true);
    getNexts(nextAvail, bit, map, index);

    vector<int> nextBits;
    makeBits(nextAvail, nextBits, 0, 0);

    ret=-1;
    for(int i=0; i<nextBits.size(); i++) {
        ret=max(ret, maxAvailStdNum(index+1, nextBits[i], map, cache)+countStdNum(bit));
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        cin>>height>>width;
        vector<string> map(height);
        vector<vector<int>> cache(width+1, vector<int>(1024, -1));
        
        //답을 한번에 구하기 위해 앞에 x 붙여줌
        for(int i=0; i<height; i++) {
            string input;
            cin>>input;
            map[i]="x"+input;
        }
        cout<<maxAvailStdNum(0, 0, map, cache)<<"\n";
    }
}