#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int paintNum, availHeight;
vector<pair<int, int>> inputs; //height, value

vector<int> cache(300000, -1);

int getLowerBound(int target, int start) {
    start--;
    int end=inputs.size();
    if(inputs.back().first>=target) {
        while(start+1<end) {
            int mid=(start+end)/2;
            if(inputs[mid].first<target) {
                start=mid;
            }
            else {
                end=mid;
            }
        }        
    }
    return end;
}

int getMax(int index) {
    if(index>=paintNum) {
        return 0;
    }

    int& ret=cache[index];
    if(ret!=-1) {
        return ret;
    }

    int nextIndex=getLowerBound(inputs[index].first+availHeight, index+1);
    ret=max(ret, getMax(index+1));
    ret=max(ret, getMax(nextIndex)+inputs[index].second);
    return ret;
}

int main() {
    cin>>paintNum>>availHeight;
    for(int i=0; i<paintNum; i++) {
        int height, value;
        cin>>height>>value;
        inputs.push_back({height, value});
    }
    sort(inputs.begin(), inputs.end());
    cout<<getMax(0);
}