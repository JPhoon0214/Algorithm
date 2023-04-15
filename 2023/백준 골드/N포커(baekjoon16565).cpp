#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(53, vector<int>(53, -1));

int combination(int total, int pick) {
    if(total==pick || pick==0) {
        return 1;
    }
    int& ret=cache[total][pick];
    if(ret!=-1) {
        return ret;
    }

    return ret=(combination(total-1, pick-1)+combination(total-1, pick))%10007;    
}

int main() {
    int cardNum;
    cin>>cardNum;

    int ret=0;
    for(int i=4; cardNum-i>=0; i+=4) {
        int currPick=i/4;
        if(currPick%2==1) {
            ret+=(combination(13, currPick)*combination(52-i, cardNum-i))%10007;
            ret%=10007;
        }
        else {
            ret-=(combination(13, currPick)*combination(52-i, cardNum-i))%10007;
            if(ret<0) {
                ret+=10007;
            }
        }
    }
    
    cout<<ret;
}