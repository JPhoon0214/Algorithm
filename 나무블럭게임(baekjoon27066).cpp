#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int sumAll=0;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
        sumAll+=nums[i];
    }
    sort(nums.begin(), nums.end());
    
    double ret=n>1 ? nums[n-2] : nums[0];
    ret=max((double)ret, (double)sumAll/n);

    cout<<fixed;
    cout.precision(10);
    cout<<ret;
}
