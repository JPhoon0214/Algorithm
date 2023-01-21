#include <iostream>
#include <vector>

using namespace std;

vector<int> cache(100000, -1);
int n, root, q;

int search(vector<vector<int>>& connect, int root, vector<bool>& visited) {
    if(visited[root])
        return -1;
    visited[root]=true;
    int& ret=cache[root];
    if(ret!=-1)
        return ret;
    
    ret=0;
    for(int i=0; i<connect[root].size(); i++) {
        ret+=(search(connect, connect[root][i], visited)+1);
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>root>>q;
    vector<vector<int>> connect(n);
    vector<bool> visited(n, false);

    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin>>v1>>v2;
        connect[v1-1].push_back(v2-1);
        connect[v2-1].push_back(v1-1);
    }
    search(connect, root-1, visited);

    for(int i=0; i<q; i++) {
        int index;
        cin>>index;
        cout<<cache[index-1]+1<<"\n";
    }
}