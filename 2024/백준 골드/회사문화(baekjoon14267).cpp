#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getRet(vector<int>& getScore, vector<vector<int> >& relation, int currIndex, int currScore) {
    getScore[currIndex]+=currScore;

    for(int i=0; i<relation[currIndex].size(); i++) {
        int nextIndex=relation[currIndex][i];
        getRet(getScore, relation, nextIndex, getScore[currIndex]);
    }
} 

int main() {
    int workerNum, inputNum;
    cin>>workerNum>>inputNum;

    vector<vector<int> > relation(workerNum);

    for(int i=0; i<workerNum; i++) {
        int parent;
        cin>>parent;

        if(parent==-1) continue;

        relation[parent-1].push_back(i);
    }

    vector<int> getScore(workerNum, 0);
    for(int i=0; i<inputNum; i++) {
        int workerIndex, score;
        cin>>workerIndex>>score;
        getScore[workerIndex-1]+=score;
    }

    getRet(getScore, relation, 0, 0);

    for(int i=0; i<workerNum; i++) {
        cout<<getScore[i]<<" ";
    }
}