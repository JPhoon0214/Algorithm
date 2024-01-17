#include <iostream>
#include <vector>

using namespace std;

int getBestScore(int first, int last, vector<int>& cards, vector<vector<int> >& cache, int currSum) {
    if(cache[first][last]!=-1) return cache[first][last];
    if(first==last) return cache[first][last]=cards[first];

    int firstMoveSum=(currSum-getBestScore(first+1, last, cards, cache, currSum-cards[first]));
    int lastMoveSum=(currSum-getBestScore(first, last-1, cards, cache, currSum-cards[last]));

    return cache[first][last]=max(firstMoveSum, lastMoveSum);
}

int main() {
    int testCase;
    cin>>testCase;

    for(; testCase>0; testCase--) {
        int cardNum;
        cin>>cardNum;

        int allSum=0;

        vector<int> cards(cardNum);
        for(int i=0; i<cardNum; i++) {
            cin>>cards[i];
            allSum+=cards[i];
        }

        vector<vector<int> > cache(cardNum, vector<int>(cardNum, -1));
        cout<<getBestScore(0, cardNum-1, cards, cache, allSum)<<"\n";
    }
}