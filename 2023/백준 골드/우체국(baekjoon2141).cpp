#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin>>n;
    
    vector<long long> cache(n, 0);

    vector<pair<int, int>> infos(n);
    for(int i=0; i<n; i++) {
        cin>>infos[i].first>>infos[i].second;
    }
    sort(infos.begin(), infos.end());

    cache[0]=infos[0].second;
    for(int i=1; i<n; i++) {
        cache[i]=cache[i-1]+infos[i].second;
    }

    long long target=(cache[n-1]+1)/2;
    int left=0;
    int right=n-1;

    int index=lower_bound(cache.begin(), cache.end(), target)-cache.begin();
    cout<<infos[index].first;
}