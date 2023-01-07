#include <iostream>
#include <vector>

using namespace std;

int getWaterHeight(vector<int>& heights, int index) {
    int maxLeft=0;
    for(int i=index-1; i>=0; i--) {
        if(heights[i]>heights[index]) {
            maxLeft=max(heights[i], maxLeft);
        }
    }

    int maxRight=0;
    for(int i=index+1; i<heights.size(); i++) {
        if(heights[i]>heights[index]) {
            maxRight=max(heights[i], maxRight);
        }
    }

    int ret=min(maxLeft, maxRight)-heights[index];
    ret=ret>=0 ? ret : 0;
    
    return ret;
}

int main() {
    int ret=0;
    int h, w;
    cin>>h>>w;
    vector<int> heights(w);
    for(int i=0; i<w; i++) {
        cin>>heights[i];
    }
    for(int i=0; i<w; i++) {
        ret+=getWaterHeight(heights, i);
    }
    cout<<ret;
}