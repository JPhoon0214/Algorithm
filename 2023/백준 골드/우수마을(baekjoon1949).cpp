#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(10000, vector<int>(3, -1));

int getValue(int root, int state, vector<int>& value, vector<vector<int>>& linked, vector<bool> visited) {
    int& ret=cache[root][state];
    if(ret!=-1)
        return ret;

    ret=0;    
    visited[root]=true;
    
    if(state==0) {
        ret+=value[root];
        for(int i=0; i<linked[root].size(); i++) {
            int nextIndex=linked[root][i];
            if(visited[nextIndex])
                continue;
            ret+=getValue(nextIndex, 1, value, linked, visited);
        }
    }
    else if(state==1) {
        for(int i=0; i<linked[root].size(); i++) {
            int nextIndex=linked[root][i];
            if(visited[nextIndex])
                continue;
            ret+=max(getValue(nextIndex, 0, value, linked, visited), getValue(nextIndex, 2, value, linked, visited));
        }
    }
    else {
        for(int i=0; i<linked[root].size(); i++) {
            int tempRet=0;
            int mustPriority=linked[root][i];
            if(visited[mustPriority])
                continue;
            tempRet+=getValue(mustPriority, 0, value, linked, visited);
            for(int j=0; j<linked[root].size(); j++) {
                if(i==j)
                    continue;
                
                int nextIndex=linked[root][j];
                if(visited[nextIndex])
                    continue;
                tempRet+=max(getValue(nextIndex, 0, value, linked, visited), getValue(nextIndex, 2, value, linked, visited));           
            }
            ret=max(ret, tempRet);
        }
    }
    return ret;
}

int main() {
    int n;
    cin>>n;
    vector<int> value(n);
    vector<vector<int>> linked(n);
    vector<bool> visited(n, false);

    for(int i=0; i<n; i++) {
        cin>>value[i];
    }
    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin>>v1>>v2;
        linked[v1-1].push_back(v2-1);
        linked[v2-1].push_back(v1-1);
    }
    cout<<max(getValue(0, 0, value, linked, visited), getValue(0, 2, value, linked, visited));
}