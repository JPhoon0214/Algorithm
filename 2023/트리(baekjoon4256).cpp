#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPostOrder(queue<int>& preOrder, vector<int>& inOrder) {
    if(inOrder.empty())
        return;
    
    int standard=preOrder.front();
    preOrder.pop();
    
    vector<int> left, right;
    vector<int>::iterator iter=inOrder.begin();
    while(iter!=inOrder.end()) {
        if(*iter==standard) {
            iter++;
            break;            
        }
        left.push_back(*iter);
        iter++;
    }
    while(iter!=inOrder.end()) {
        right.push_back(*iter);
        iter++;
    }

    vector<int>().swap(inOrder);
    printPostOrder(preOrder, left);
    printPostOrder(preOrder, right);
    cout<<standard<<" ";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        int nodeNum;
        cin>>nodeNum;
        queue<int> preOrder;
        vector<int> inOrder(nodeNum);
        for(int i=0; i<nodeNum; i++) {
            int input;
            cin>>input;
            preOrder.push(input);
        }
        for(int i=0; i<nodeNum; i++) {
            cin>>inOrder[i];
        }
        printPostOrder(preOrder, inOrder);
        cout<<"\n";
    }
}