#include <iostream>
#include <vector>

using namespace std;

void makeRet(vector<int>& nodes, vector<int>& ret) {
    if(nodes.empty())
        return;

    int standard=nodes[0];
    vector<int> lessNodes;
    vector<int> greaterNodes;
    for(int index=1; index<nodes.size(); index++) {
        int curr=nodes[index];
        if(curr<standard) {
            lessNodes.push_back(curr);
        }
        else {
            greaterNodes.push_back(curr);
        }
    }
    vector<int>().swap(nodes);
    ret.push_back(standard);
    makeRet(greaterNodes, ret);
    makeRet(lessNodes, ret);
}

int main() {
    vector<int> nodes;
    vector<int> ret;

    while(true) {
        int input;
        cin>>input;
        if(cin.eof()) {
            break;
        }
        nodes.push_back(input);
    }    
    makeRet(nodes, ret);
    while(!ret.empty()) {
        cout<<ret.back()<<"\n";
        ret.pop_back();
    }
}