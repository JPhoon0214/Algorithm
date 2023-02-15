#include <iostream>
#include <vector>

using namespace std;

bool dfs(int index, vector<vector<int>>& availWorks, vector<int>& matching, vector<bool>& visited) {
    for(int i=0; i<availWorks[index].size(); i++) {
        int workIndex=availWorks[index][i];

        if(visited[workIndex]) {
            continue;
        }
        visited[workIndex]=true;

        if(matching[workIndex]==-1 || dfs(matching[workIndex], availWorks, matching, visited)) {
            matching[workIndex]=index;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int workerNum, workNum;
    cin>>workerNum>>workNum;

    vector<vector<int>> availWorks(workerNum);

    for(int i=0; i<workerNum; i++) {
        int availWorkNum;
        cin>>availWorkNum;
        availWorks[i]=vector<int>(availWorkNum);
        for(int j=0; j<availWorkNum; j++) {
            cin>>availWorks[i][j];
        }
    }

    vector<int> matching(workNum+1, -1);

    int cnt=0;
    for(int i=0; i<workerNum; i++) {
        vector<bool> visited(workNum+1, false);

        if(dfs(i, availWorks, matching, visited)) {
            cnt++;
        }
    }
    cout<<cnt;
}