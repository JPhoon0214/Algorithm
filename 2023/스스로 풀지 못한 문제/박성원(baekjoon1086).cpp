#include <iostream>
#include <vector>
#include <string>

using namespace std;

int divider;
int inputNum;
vector<string> inputs(20);
vector<int> remains(20);
vector<int> levelCache(60);

int getRemain(string num, int ret) {
    if(num.empty())
        return ret;
    
    int currNum=num[0]-'0';
    ret*=10;
    ret+=currNum;
    ret%=divider;
    return getRemain(num.substr(1), ret);
}

void setCache(vector<vector<long long>>& cache, int alreadySelected, int currSelected, int level) {
    for(int i=0; i<divider; i++) {
        int currStrSize=inputs[level].size();
        int nextRemain=i;
        /*
        for(int strSize=0; strSize<currStrSize; strSize++) {
            nextRemain*=10;
            nextRemain%=divider;
        }*/
        nextRemain*=levelCache[currStrSize];
        nextRemain%=divider;
        nextRemain+=remains[level];
        nextRemain%=divider;
        cache[alreadySelected+currSelected][nextRemain]+=cache[alreadySelected][i];
    }
}

long long getGreatestCommonDivisor(long long bigger, long long smaller) {
    if(bigger%smaller==0)
        return smaller;
    return getGreatestCommonDivisor(smaller, bigger%smaller);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>inputNum;
    for(int i=0; i<inputNum; i++) {
        cin>>inputs[i];
    }
    
    cin>>divider;
    for(int i=0; i<inputNum; i++) {
        string target=inputs[i];
        remains[i]=getRemain(target, 0);
    }

    int levelTemp=10;
    levelTemp%=divider;
    levelCache[1]=levelTemp;
    for(int i=2; i<60; i++) {
        levelCache[i]=levelCache[i-1];
        levelCache[i]*=levelTemp;
        levelCache[i]%=divider;
    }

    vector<vector<long long>> cache(32768, vector<long long>(100, 0));
    cache[0][0]=1;

    int allChoose=1<<inputNum;
    for(int selected=0; selected<allChoose; selected++) {
        int tempSelected=selected;
        int level=0;
        while(tempSelected!=0) {
            if(tempSelected%2==1) {
                int target=1<<level;
                setCache(cache, selected-target, target, level);
            }
            tempSelected/=2;
            level++;
        }
    }

    long long totalCase=1;
    for(int i=1; i<=inputNum; i++) {
        totalCase*=i;
    }
    long long ret=cache[allChoose-1][0];

    if(ret==0) {
        cout<<"0/1";
    }
    else {
        long long divisor=getGreatestCommonDivisor(totalCase, ret);
        ret/=divisor; totalCase/=divisor;
        cout<<ret<<"/"<<totalCase;
    }
}