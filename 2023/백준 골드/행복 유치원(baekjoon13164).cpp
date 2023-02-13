#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int childNum, groupNum;
    cin>>childNum>>groupNum;
    vector<int> heights(childNum);
    for(int i=0; i<childNum; i++) {
        cin>>heights[i];
    }
    sort(heights.begin(), heights.end());

    vector<int> gaps(childNum-1);
    for(int i=1; i<childNum; i++) {
        gaps[i-1]=heights[i]-heights[i-1];
    }

    sort(gaps.begin(), gaps.end());

    int ret=0;
    for(int i=0; i<gaps.size()-groupNum+1; i++) {
        ret+=gaps[i];
    }
    cout<<ret;
}