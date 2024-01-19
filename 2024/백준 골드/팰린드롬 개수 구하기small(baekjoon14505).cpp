#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > cache(30, vector<int>(30, -1));

int getCaseNum(int leftMid, int rightMid, string& str) {
    if(str[leftMid]!=str[rightMid]) return cache[leftMid][rightMid]=0;
    if(cache[leftMid][rightMid]!=-1) return cache[leftMid][rightMid];

    int ret=1;
    for(int left=leftMid-1; left>=0; left--) {
        for(int right=rightMid+1; right<str.size(); right++) {
            ret+=getCaseNum(left, right, str);
        }
    }
    return cache[leftMid][rightMid]=ret;
}

int main() {
    int ret=0;
    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++) {
        for(int j=i; j<str.size(); j++) {
            ret+=getCaseNum(i, j, str);
        }
    }

    cout<<ret;
}