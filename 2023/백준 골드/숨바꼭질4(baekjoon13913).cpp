#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printRoad(vector<int>& cache, int index, int time) {
    if(time<0)
        return;
    
    int nextIndex=-1;
    for(int i=0; i<3; i++) {
        if(i==0) {
            if(index%2==1)
                continue;
            if(cache[index/2]==time-1) {
                nextIndex=index/2;
                break;
            }
        }
        else if(i==1) {
            if(cache[index+1]==time-1) {
                nextIndex=index+1;
                break;
            }
        }
        else {
            if(index-1>=0 && cache[index-1]==time-1) {
                nextIndex=index-1;
                break;
            }
        }
    }
    printRoad(cache, nextIndex, time-1);
    cout<<index<<" ";
}

int main() {
    int start, target;
    cin>>start>>target;
    
    queue<pair<int, int>> poses;
    poses.push({start, 0});

    vector<int> cache(1000000, -1);
    cache[start]=0;

    while(!poses.empty()) {
        int pos=poses.front().first;
        int times=poses.front().second;
        poses.pop();

        for(int i=0; i<3; i++) {
            int nextPos;
            if(i==0) {
                nextPos=pos*2;
            }
            else if(i==1) {
                nextPos=pos+1;
            }
            else {
                nextPos=pos-1;
            }
            
            if(pos<0 || (pos>target && i!=2))
                continue;
            if(cache[nextPos]!=-1)
                continue;
            
            cache[nextPos]=times+1;
            if(nextPos==target)
                break;

            poses.push({nextPos, times+1});
        }
    }
    cout<<cache[target]<<"\n";
    printRoad(cache, target, cache[target]);
}