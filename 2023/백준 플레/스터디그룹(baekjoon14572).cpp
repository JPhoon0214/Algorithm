#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getValue(int stdNum, vector<int>& state) {
    int cnt=0;
    for(int i=0; i<state.size(); i++) {
        if(state[i]>0 && state[i]<stdNum) {
            cnt++;
        }
    }
    return cnt*stdNum;
}

void setState(vector<pair<int, int>>& stdValue, vector<vector<int>>& stdKnowAlgo, vector<int>& state, int ptr, int flag) {
    int currPtr=stdValue[ptr].second;
    for(int i=0; i<stdKnowAlgo[currPtr].size(); i++) {
        int currAlgoIndex=stdKnowAlgo[currPtr][i];
        state[currAlgoIndex]+=flag;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int stdNum, algoNum, availGap;
    cin>>stdNum>>algoNum>>availGap;

    vector<pair<int, int>> stdValue(stdNum);
    vector<vector<int>> stdKnowAlgo(stdNum, vector<int>());

    for(int i=0; i<stdNum; i++) {
        int currKnowAlgoNum;
        cin>>currKnowAlgoNum>>stdValue[i].first;
        stdValue[i].second=i;

        for(int j=0; j<currKnowAlgoNum; j++) {
            int algoIndex;
            cin>>algoIndex;
            stdKnowAlgo[i].push_back(algoIndex-1);
        }
    }

    sort(stdValue.begin(), stdValue.end());

    int ret=0;

    int startPoint=0, endPoint=0;
    vector<int> state(algoNum, 0);

    setState(stdValue, stdKnowAlgo, state, 0, 1);

    while(true) {
        if(stdValue[endPoint].first-stdValue[startPoint].first>availGap) {
            setState(stdValue, stdKnowAlgo, state, startPoint, -1);
            startPoint++;
            continue;
        }

        ret=max(ret, getValue(endPoint-startPoint+1, state));

        endPoint++;
        if(endPoint>=stdNum) break;
        setState(stdValue, stdKnowAlgo, state, endPoint, 1);        
    }
    
    cout<<ret;
}