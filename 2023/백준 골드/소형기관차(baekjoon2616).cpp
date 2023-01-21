#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(50001, vector<int>(3, -1));
vector<int> sumValue;

int getMax(int smallLinked, int index, int picked) {
    if(picked==3) {
        return 0;
    }
    if(index>=sumValue.size()) {
        return -987654321;
    }
    int& ret=cache[index][picked];
    if(ret!=-1)
        return ret;

    ret=-987654321;
    ret=max(sumValue[index]+getMax(smallLinked, index+smallLinked, picked+1), getMax(smallLinked, index+1, picked));
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> value(n);
    for(int i=0; i<n; i++) {
        cin>>value[i];
    }
    int smallLinked;
    cin>>smallLinked;

    int smallSum=0;
    for(int i=0; i<smallLinked; i++) {
        smallSum+=value[i];
    }
    sumValue.push_back(smallSum);
    for(int i=smallLinked; i<n; i++) {
        smallSum+=value[i];
        smallSum-=value[i-smallLinked];
        sumValue.push_back(smallSum);
    }

    cout<<getMax(smallLinked, 0, 0);
}