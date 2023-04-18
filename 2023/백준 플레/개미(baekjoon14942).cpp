#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int>& nextVertex, vector<int>& nextCost, vector<vector<int>>& linked, vector<vector<int>>& costs, vector<bool>& visited) {
    visited[v]=true;
    
    for(int i=0; i<linked[v].size(); i++) {
        int nextV=linked[v][i];
        if(visited[nextV]) continue;

        nextVertex[nextV]=v;
        nextCost[nextV]=costs[v][i];

        dfs(nextV, nextVertex, nextCost, linked, costs, visited);
    }
}

int main() {
    int n;
    cin>>n;

    vector<pair<int, int>> antInfo(n);
    for(int i=0; i<n; i++) {
        cin>>antInfo[i].first;
        antInfo[i].second=i+1;
    }

    vector<vector<int>> linked(n+1);
    vector<vector<int>> costs(n+1);
    for(int i=0; i<n-1; i++) {
        int v1, v2, cost;
        cin>>v1>>v2>>cost;
        
        linked[v1].push_back(v2);
        linked[v2].push_back(v1);

        costs[v1].push_back(cost);
        costs[v2].push_back(cost);
    }

    vector<bool> visited(n+1, false);
    vector<int> nextVertex(n+1);
    vector<int> nextCost(n+1);

    dfs(1, nextVertex, nextCost, linked, costs, visited);

    for(int i=0; i<antInfo.size(); i++) {
        int currPower=antInfo[i].first;
        int currV=antInfo[i].second;
        
        
        while(currPower>=nextCost[currV] && currV!=1) {
            currPower-=nextCost[currV];
            currV=nextVertex[currV];
        }

        cout<<currV<<"\n";
    }
}