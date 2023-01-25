#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(2000, vector<int>(2000, -1));

int n;

int getMax(vector<int>& left, vector<int>& right, int leftIndex, int rightIndex) {
    if(leftIndex==n || rightIndex==n) {
        return 0;
    }
    int& ret=cache[leftIndex][rightIndex];
    if(cache[leftIndex][rightIndex]!=-1) {
        return ret;
    }
    ret=max(ret, getMax(left, right, leftIndex+1, rightIndex));
    ret=max(ret, getMax(left, right, leftIndex+1, rightIndex+1));
    if(left[leftIndex]>right[rightIndex]) {
        ret=max(ret, getMax(left, right, leftIndex, rightIndex+1)+right[rightIndex]);
    }
    return ret;
}

int main() {
    cin>>n;
    vector<int> left(n);
    vector<int> right(n);
    for(int i=0; i<n; i++) {
        cin>>left[i];
    }
    for(int i=0; i<n; i++) {
        cin>>right[i];
    }
    cout<<getMax(left, right, 0, 0); 
}