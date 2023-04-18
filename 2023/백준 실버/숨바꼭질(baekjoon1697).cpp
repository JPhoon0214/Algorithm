#include <iostream>
#include <queue>

using namespace std;

struct Info {
    int pos;
    int time;
};

int main() {
    int myPos, targetPos;
    cin>>myPos>>targetPos;

    queue<Info> que;
    que.push({myPos, 0});

    vector<bool> visited(100001, false);

    while(!que.empty()) {
        int currPos=que.front().pos;
        int currTime=que.front().time;
        que.pop();

        visited[currPos]=true;

        if(currPos==targetPos) {
            cout<<currTime;
            break;
        }

        if(currPos+1<=100000 && !visited[currPos+1]) {
            que.push({currPos+1, currTime+1});
        }
        if(currPos-1>=0 && !visited[currPos-1]) {
            que.push({currPos-1, currTime+1});
        }
        if(currPos*2<=100000 && !visited[currPos*2]) {
            que.push({currPos*2, currTime+1});
        }
    }
}