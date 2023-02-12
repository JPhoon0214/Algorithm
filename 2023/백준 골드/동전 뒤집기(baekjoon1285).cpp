#include <iostream>
#include <vector>

using namespace std;

int mapSize;

void upSideDown(vector<vector<int>>& map, int index) {
    for(int i=0; i<mapSize; i++) {
        map[index][i]++;
    }        
}

int getMin(vector<vector<int>>& map, int index) {
    if(index==mapSize) {
        int ret=0;
        for(int i=0; i<mapSize; i++) {
            int countUp=0;
            for(int j=0; j<mapSize; j++) {
                if(map[j][i]%2==0)
                    countUp++;
            }
            ret+=min(countUp, mapSize-countUp);
        }
        return ret;
    }
    
    int ret;
    ret=getMin(map, index+1);
    
    upSideDown(map, index);
    ret=min(getMin(map, index+1), ret);

    upSideDown(map, index);
    
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>mapSize;
    vector<vector<int>> map(mapSize, vector<int>(mapSize));
    for(int i=0; i<mapSize; i++) {
        string input;
        cin>>input;
        for(int j=0; j<mapSize; j++) {
            if(input[j]=='H') {
                map[i][j]=0;
            }
            else {
                map[i][j]=1;
            }
        }
    }
    cout<<getMin(map, 0);
} 