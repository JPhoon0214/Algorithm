#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Emoticon {
    int screen;
    int clipBoard;
    int times;
};

int main() {
    int target;
    cin>>target;
    queue<Emoticon> emoticons;
    emoticons.push({1, 0, 0});
    vector<vector<bool>> visited(2000, vector<bool>(2000, false));
    
    int ret=0;    
    while(!emoticons.empty()) {
        if(ret!=0)
            break;
        int screen=emoticons.front().screen;
        int clipBoard=emoticons.front().clipBoard;
        int times=emoticons.front().times;
        emoticons.pop();

        for(int i=0; i<3; i++) {
            int nextScreen=screen, nextClipBoard=screen;
            if(i==0) {
                nextScreen=screen;
                nextClipBoard=screen;
            }
            else if(i==1) {
                nextScreen=screen+clipBoard;
                nextClipBoard=clipBoard;
            }
            else {
                nextScreen=screen-1;
                nextClipBoard=clipBoard;
            }
            if(nextScreen<0 || nextScreen>=2000 || nextClipBoard<0 || nextClipBoard>=2000)
                continue;
            if(visited[nextScreen][nextClipBoard])
                continue;
            if(nextScreen==target) {
                ret=times+1;
                break;
            }
            visited[nextScreen][nextClipBoard]=true;
            emoticons.push({nextScreen, nextClipBoard, times+1});
        }
    }
    cout<<ret;
}