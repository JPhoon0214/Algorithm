#include <iostream>
#include <vector>

using namespace std;

int companyNum;
vector<vector<int>> cache(20, vector<int>(301, -1));

int getMax(vector<vector<int>>& value, int index, int money) {
    if(index==companyNum) {
        if(money==0) {
            return 0;
        }
        else {
            return -987654321;
        }
    }
    
    int& ret=cache[index][money];
    if(ret!=-1) {
        return ret;
    }

    int putMoney=-1;    
    for(int i=0; i<=money; i++) {
        int currRet=getMax(value, index+1, money-i)+value[index][i];
        if(ret<currRet) {
            ret=currRet;
            putMoney=i;            
        }
    }
    return ret;
}

void getAns(vector<vector<int>>& value, int index, int money, int target) {
    if(index+1==companyNum) {
        for(int i=0; i<=money; i++) {
            if(value[index][i]==target) {
                cout<<i;
                return;
            }
        }
    }
    
    for(int i=0; i<=money; i++) {
        if(cache[index+1][money-i]+value[index][i]==target) {
            cout<<i<<" ";
            getAns(value, index+1, money-i, target-value[index][i]);
            break;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int money;
    cin>>money>>companyNum;
    vector<vector<int>> value(companyNum, vector<int>(money+1, 0));
    for(int i=0; i<money; i++) {
        int currMoney;
        cin>>currMoney;
        for(int j=0; j<companyNum; j++) {
            cin>>value[j][currMoney];
        }
    }

    int ret=getMax(value, 0, money);
    cout<<ret<<"\n";
    getAns(value, 0, money, ret);
}