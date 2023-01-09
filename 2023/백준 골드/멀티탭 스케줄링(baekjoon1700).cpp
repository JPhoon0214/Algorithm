#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int availUseOnce, dataNum;
    cin>>availUseOnce>>dataNum;
    vector<int> process(dataNum);
    for(int i=0; i<dataNum; i++) {
        cin>>process[i];
    }

    vector<int> nextProcessIndex(dataNum, 987654321);
    for(int i=0; i<dataNum; i++) {
        for(int j=i+1; j<dataNum; j++) {
            if(process[i]==process[j]) {
                nextProcessIndex[i]=j;
                break;
            }
        }
    }

    int ret=0;
    vector<int> working;
    for(int i=0; i<dataNum; i++) {
        bool isAlready=false;
        for(int j=0; j<working.size(); j++) {
            if(process[working[j]]==process[i]) {
                working[j]=i;
                isAlready=true;
                break;
            }
        }
        if(isAlready)
            continue;
        
        if(working.size()<availUseOnce) {
            working.push_back(i);
        }
        else {
            int maxData=-1;
            int maxIndex=-1;
            for(int j=0; j<working.size(); j++) {
                if(maxData<nextProcessIndex[working[j]]) {
                    maxData=nextProcessIndex[working[j]];
                    maxIndex=j;
                }
            }
            working[maxIndex]=i;    
            ret++;
        }
    }
    cout<<ret;
}