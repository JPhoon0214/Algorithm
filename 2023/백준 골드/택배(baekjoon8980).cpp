#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cityNum, capacity;

int ret=0;

void moveBoxes(int city, vector<pair<int, int>>& already, vector<vector<int>>& cityToCity) {
    if(city==cityNum) {
        return;
    }
    
    while(!already.empty()) {
        pair<int, int> curr=already.back();
        if(curr.first==city) {
            ret+=curr.second;
            already.pop_back();
        }
        else {
            break;
        }
    }

    vector<pair<int, int>> newContainer;
    int remainCapacity=capacity;
    int cityPointer=city+1;
    while(remainCapacity>0) {        
        if(already.empty() || already.back().first>cityPointer) {
            int moveBox=remainCapacity>=cityToCity[city][cityPointer] ? cityToCity[city][cityPointer] : remainCapacity;
            
            if(moveBox>0)
                newContainer.push_back({cityPointer, moveBox});
            
            remainCapacity-=moveBox;
            cityPointer++;
        }
        else {
            pair<int, int> curr=already.back();
            int moveBox=remainCapacity>=curr.second ? curr.second : remainCapacity;
            
            if(moveBox>0)
                newContainer.push_back({curr.first, moveBox});
            
            remainCapacity-=moveBox;
            already.pop_back();
        }
    }
    
    already=newContainer;
    reverse(already.begin(), already.end());

    moveBoxes(city+1, already, cityToCity);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>cityNum>>capacity;
    vector<vector<int>> cityToCity(cityNum, vector<int>(cityNum, 0));
        
    int infoNum;
    cin>>infoNum;
    for(int i=0; i<infoNum; i++) {
        int start, end, amount;
        cin>>start>>end>>amount;
        cityToCity[start-1][end-1]=amount;
    }    

    vector<pair<int, int>> already;
    moveBoxes(0, already, cityToCity);
    cout<<ret;
}