#include <iostream>
#include <vector>

using namespace std;

vector<int> cost;
vector<int> value;

vector<int> cache(2000, -1);

int getMinCost(int target) {
    if(target<=0) {
        return 0;
    }
    int& ret=cache[target];
    if(ret!=-1) {
        return ret;
    }

    ret=987654321;
    for(int i=0; i<cost.size(); i++) {
        ret=min(ret, cost[i]+getMinCost(target-value[i]));
    }
    return ret;
}

int main() {
    int target, cityNum;
    cin>>target>>cityNum;
    for(int i=0; i<cityNum; i++) {
        int cityCost, cityValue;
        cin>>cityCost>>cityValue;
        cost.push_back(cityCost);
        value.push_back(cityValue);
    }
    cout<<getMinCost(target);
}