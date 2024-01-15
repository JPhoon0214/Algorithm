#include <iostream>
#include <vector>

using namespace std;

int MAXCOIN=987654321;

vector<int> cache(100001, MAXCOIN);

int getCoinNum(int money) {
    if(money<0) return MAXCOIN;
    if(money==0) return 0;
    if(cache[money]!=MAXCOIN) return cache[money];

    cache[money]=min(getCoinNum(money-2), getCoinNum(money-5))+1;
    return cache[money];
}

int main() {
    int money;
    cin>>money;
    
    int ret=getCoinNum(money);
    ret<MAXCOIN ? cout<<ret : cout<<-1;
}