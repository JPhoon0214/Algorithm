#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int numValue[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 5};

// cache[s][l][k]: 합이 s이고 길이가 l인 숫자 중에서 k00... 나 그 이후로 나오는 숫자 중 가장 먼저 나오는 수
// -1: 아직 검사 안함. -2: befMax 상황에선 불가능했음.
vector<vector<vector<long long> > > cache(150, vector<vector<long long> >(16, vector<long long>(10, -1LL)));

long long stringToLongLongConvert(string str) {
    long long ret=0LL;
    long long currLevel=1LL;
    while(!str.empty()) {
        ret+=((str.back()-'0')*currLevel);
        str.pop_back();
        currLevel*=10;
    }
    return ret;
}

// 끝에서 level 만큼 숫자를 비교했을 때 선분 개수가 같은 가장 먼저 나오는 수를 리턴. 불가능하다면 -2 리턴.
long long getBefMaxInLevel(int higherThan, int level, int targetSum) {
    if(higherThan>9 || targetSum<0) return -2;
    if(cache[targetSum][level][higherThan]!=-1) return cache[targetSum][level][higherThan];
    if(level==1) {
        for(int i=higherThan; i<10; i++) {
            if(targetSum==numValue[i]) return cache[targetSum][level][higherThan]=i;
        }
        return cache[targetSum][level][higherThan]=-2LL;
    }

    long long digitCal=1LL;
    for(int i=0; i<level-1; i++) {
        digitCal*=10;
    }

    for(int i=higherThan; i<10; i++) {
        long long currRet=getBefMaxInLevel(0, level-1, targetSum-numValue[i]);
        if(currRet==-2) continue;

        return cache[targetSum][level][higherThan]=i*digitCal + currRet;
    }
    return cache[targetSum][level][higherThan]=-2LL;
}

long long getBefMax(string input, vector<int>& linesSum) {
    int level=0;
    long long digitCal=1LL;
    while(!input.empty()) {
        int last=input.back()-'0';
        input.pop_back();
        level++;
        digitCal*=10;

        long long currRet=getBefMaxInLevel(last+1, level, linesSum[input.size()]);
        if(currRet!=-2) return stringToLongLongConvert(input)*digitCal+currRet;
    }
    return -1LL;
}

long long getAftMaxInLevel(int lowerThan, int level, int targetSum) {
    if(lowerThan<0 || targetSum<0) return -3LL;
    if(cache[targetSum][level][lowerThan]==-2) cache[targetSum][level][lowerThan]=-1;
    if(cache[targetSum][level][lowerThan]!=-1) return cache[targetSum][level][lowerThan];
    if(level==1) {
        for(int i=0; i<=lowerThan; i++) {
            if(targetSum==numValue[i]) return cache[targetSum][level][lowerThan]=i;
        }
        return cache[targetSum][level][lowerThan]=-3LL;
    }

    long long digitCal=1LL;
    for(int i=0; i<level-1; i++) {
        digitCal*=10;
    }

    for(int i=0; i<=lowerThan; i++) {
        long long currRet=getAftMaxInLevel(9, level-1, targetSum-numValue[i]);
        if(currRet==-3) continue;

        return cache[targetSum][level][lowerThan]=i*digitCal + currRet;
    }
    return cache[targetSum][level][lowerThan]=-3LL;
}

long long getAftMax(string input, vector<int>& linesSum) {
    int level=0;
    long long digitCal=1LL;
    long long ret=-1LL;
    while(!input.empty()) {
        int last=input.back()-'0';
        input.pop_back();
        level++;
        digitCal*=10;

        long long currRet=getAftMaxInLevel(last-1, level, linesSum[input.size()]);
        if(currRet!=-3) ret=stringToLongLongConvert(input)*digitCal+currRet;
    }
    return ret;
}

int main() {
    string input;
    cin>>input;

    vector<int> linesSum(input.size()+1, 0);
    for(int i=input.size()-1; i>=0; i--) {
        linesSum[i]=linesSum[i+1]+numValue[input[i]-'0'];
    }

    long long original=stringToLongLongConvert(input);
    long long maxNum=1LL;
    for(int i=0; i<input.size(); i++) maxNum*=10;

    long long retBefMax=getBefMax(input, linesSum);
    if(retBefMax!=-1) {
        cout<<retBefMax-original;
    }
    else {
        long long retAftMax=getAftMax(input, linesSum);
        if(retAftMax!=-1) {
            cout<<retAftMax+maxNum-original;
        }
        else {
            cout<<maxNum;
        }
    }
}