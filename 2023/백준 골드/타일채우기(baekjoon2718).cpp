#include <iostream>
#include <vector>

using namespace std;

int calCaseNum(vector<vector<int>>& cache, int remainWidth, int type);

int calCase0(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-2, 0);
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-1, 1);
    ret+=calCaseNum(cache, remainWidth-1, 2);
    ret+=calCaseNum(cache, remainWidth-1, 3);
    return ret;
}

int calCase1(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-1, 2);
    return ret;
}

int calCase2(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-1, 1);
    return ret;
}

int calCase3(vector<vector<int>>& cache, int remainWidth) {
    int ret=0;
    ret+=calCaseNum(cache, remainWidth-1, 0);
    ret+=calCaseNum(cache, remainWidth-2, 3);
    return ret;
}


int calCaseNum(vector<vector<int>>& cache, int remainWidth, int type) {
    if(remainWidth<0) {
        return 0;
    }
    if(remainWidth==0 && type==0) {
        return 1;
    }
    
    int& ret=cache[remainWidth][type];
    if(ret!=-1) {
        return ret;
    }
    
    if(type==0) {
        ret=calCase0(cache, remainWidth);
    }
    else if(type==1) {
        ret=calCase1(cache, remainWidth);
    }
    else if(type==2) {
        ret=calCase2(cache, remainWidth);
    }
    else if(type==3) {
        ret=calCase3(cache, remainWidth);
    }
    return ret;
}

int main() {
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        int width;
        cin>>width;
        vector<vector<int>> cache(width+1, vector<int>(5, -1));
        cout<<calCaseNum(cache, width, 0)<<"\n";
    }
}