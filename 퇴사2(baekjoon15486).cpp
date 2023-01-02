#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> cache(n+1, 0);
    vector<pair<int, int>> inputs(n);
    for(int i=0; i<n; i++) {
        cin>>inputs[i].first>>inputs[i].second;
    }

    int befHighestCost=-1;
    for(int i=0; i<n; i++) {
        befHighestCost=max(befHighestCost, cache[i]);
        int period=inputs[i].first;
        int day=i+1;
        if(day+period-1>n)
            continue;
        cache[day+period-1]=max(cache[day+period-1], befHighestCost+inputs[i].second);
    }

    int ret=0;
    for(int i=0; i<n+1; i++) {
        ret=max(ret, cache[i]);
    }
    cout<<ret;
}
