#include <iostream>
#include <vector>

using namespace std;

long long cutTrees(int standard, vector<int>& trees) {
    long long ret=0;
    for(int i=0; i<trees.size(); i++) {
        if(standard<trees[i]) {
            ret+=(trees[i]-standard);
        }
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int treeNum, target;
    cin>>treeNum>>target;
    vector<int> trees(treeNum);
    int maxHeight=0;
    
    for(int i=0; i<treeNum; i++) {
        cin>>trees[i];
        maxHeight=max(maxHeight, trees[i]);
    }

    int left=0;
    int right=maxHeight;
    while(left+1<right) {
        int mid=(left+right)/2;
        long long getWood=cutTrees(mid, trees);
        if(getWood>target) {
            left=mid;
        }
        else {
            right=mid;
        }
    }
    int ret=left;
    if(cutTrees(right, trees)>=target)
        ret=right;
    if(cutTrees)
    cout<<ret;
}
