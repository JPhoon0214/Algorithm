#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>> poses;
vector<int> minMoves(1000000, 987654321);

int main() {
    int start, target;
    cin>>start>>target;

    int minMove=987654321;
    int caseNum=0;

    if(start==target) {
        cout<<0<<"\n";
        cout<<1;        
    }
    else {
        poses.push({start, 0});
        while(!poses.empty()) {
            int pos=poses.front().first;
            int time=poses.front().second;
            poses.pop();
    
            if(time>=minMove || (0<=pos && pos<1000000 && minMoves[pos]<time))
                continue;
            
            minMoves[pos]=time;
    
            long long next;
            if(pos>0) {
                next=pos-1;
                if(next==target) {
                    minMove=time+1;
                    caseNum++;
                }
                else {
                    poses.push({next, time+1});
                }
            }
            if(pos<target) {
                next=pos+1;
                if(next==target) {
                    minMove=time+1;
                    caseNum++;
                }
                else {
                    poses.push({next, time+1});
                }
    
                next=pos*2;
                if(next==target) {
                    minMove=time+1;
                    caseNum++;
                }
                else {
                    poses.push({next, time+1});
                }
            }
        }
        cout<<minMove<<"\n";
        cout<<caseNum;        
    }
}
