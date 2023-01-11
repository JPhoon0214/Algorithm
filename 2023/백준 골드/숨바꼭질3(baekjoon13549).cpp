#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int start, target;
    cin>>start>>target;
    deque<pair<int, int>> poses;
    poses.push_back({start, 0});
    vector<int> cache(1000000, 987654321);

    int ret=0;
    while(!poses.empty()) {
        int pos=poses.front().first;
        int times=poses.front().second;
        poses.pop_front();

        //처음부터 수빈이와 동생의 위치가 같은 경우
        if(pos==target)
            break;

        for(int i=0; i<3; i++) {
            int nextPos, nextTimes;
            if(i==0) {
                nextPos=pos*2;
                nextTimes=times;
            }
            else if(i==1) {
                nextPos=pos+1;
                nextTimes=times+1;
            }
            else {
                nextPos=pos-1;
                nextTimes=times+1;
            }

            if(nextPos<0 || (pos>target && i!=2))
                continue;
            
            if(cache[nextPos]<=nextTimes)
                continue;
            else
                cache[nextPos]=nextTimes;
            
            if(nextPos==target) {
                ret=nextTimes;
                break;
            }
            
            if(i==0) {
                poses.push_front({nextPos, nextTimes});
            }
            else {
                poses.push_back({nextPos, nextTimes});
            }
        }
    }
    cout<<ret;
}