//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
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums({1, 3, 5, 7, 9, 11});

    int target=9;

    int lo=-1, hi=nums.size();
    while(lo+1<hi) {
        int mid=(lo+hi)/2;
        if(nums[mid]<target) {
            lo=mid;
        }
        else {
            hi=mid;
        }
    }
    int ret=nums[hi];
}