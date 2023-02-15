#include <iostream>
#include <vector>

using namespace std;

bool dfs(int index, vector<vector<int>>& wishHouse, vector<bool>& visited, vector<int>& owner) {
    for(int i=0; i<wishHouse[index].size(); i++) {
        int houseIndex=wishHouse[index][i];
        if(visited[houseIndex]) {
            continue;
        }
        visited[houseIndex]=true;
        if(owner[houseIndex]==-1 || dfs(owner[houseIndex], wishHouse, visited, owner)) {
            owner[houseIndex]=index;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cowNum, houseNum;
    cin>>cowNum>>houseNum;

    //wishHouse[i]: i번째 소가 들어가고 싶어하는 축사 그룹
    vector<vector<int>> wishHouse(cowNum);
    for(int i=0; i<cowNum; i++) {
        int wishNum;
        cin>>wishNum;
        wishHouse[i]=vector<int>(wishNum);
        for(int j=0; j<wishNum; j++) {
            cin>>wishHouse[i][j];
        }
    }

    //owner[i]: i번째 축사에 들어간 소의 번호
    vector<int> owner(houseNum+1, -1);
    
    int cnt=0;
    for(int i=0; i<cowNum; i++) {
        //visited[i]: i번째 축사가 배정된 적이 있는가
        vector<bool> visited(houseNum+1, false);

        if(dfs(i, wishHouse, visited, owner)) {
            cnt+=1;
        }
    }
    cout<<cnt;
}