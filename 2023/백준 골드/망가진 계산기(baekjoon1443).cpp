#include <iostream>
#include <vector>
#include <string>

using namespace std;

int availShow, calNum;

int calReturn(vector<int>& countPerNum) {
    int ret=1;
    for(int i=2; i<10; i++) {
        for(int j=0; j<countPerNum[i]; j++) {
            ret*=i;
            string retToString=to_string(ret);
            if(retToString.size()>availShow) {
                return -1;
            }
        }
    }
    
    return ret;
}

int getMax(int currNum, vector<int>& countPerNum, int remain) {
    if(currNum==10) {        
        return calReturn(countPerNum);
    }
    else if(currNum==9) {
        countPerNum[currNum]=remain;
        int ret=getMax(currNum+1, countPerNum, 0);
        countPerNum[currNum]=0;
        return ret;
    }
    
    int ret=-1;    
    
    for(int i=remain; i>=0; i--) {
        countPerNum[currNum]=i;
        int currMax=getMax(currNum+1, countPerNum, remain-i);
        countPerNum[currNum]=0;
        
        if(currMax==-1) {
            break;
        }        
        ret=max(ret, currMax);
    }
    return ret;
}

int main() {
    cin>>availShow>>calNum;
    vector<int> countPerNum(10, 0);
    cout<<getMax(2, countPerNum, calNum);
}