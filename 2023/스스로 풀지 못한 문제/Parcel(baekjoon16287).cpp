#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int target, n;
    cin>>target>>n;

    vector<int> inputs(n);
    for(int i=0; i<n; i++) {
        cin>>inputs[i];
    }
    sort(inputs.begin(), inputs.end());

    vector<bool> cache(1000000, false);

    bool isExist=false;    

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(inputs[i]+inputs[j]>=target)
                break;
            
            int currSum=inputs[i]+inputs[j];
            if(cache[target-currSum]) {
                isExist=true;
                break;
            }
        }

        for(int j=0; j<i; j++) {
            int availCase=inputs[j]+inputs[i];
            cache[availCase]=true;
        }
    }

    if(isExist) cout<<"YES";
    else cout<<"NO";
}