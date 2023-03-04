#include <iostream>
#include <vector>

using namespace std;

bool checkPPAP(vector<char>& lets) {
    if(lets.size()<4) {
        return false;
    }

    string target="PPAP";
    
    for(int i=lets.size()-4; i<lets.size(); i++) {
        if(lets[i]!=target[i-(lets.size()-4)]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    cin>>input;

    vector<char> temp;

    for(int i=0; i<input.size(); i++) {
        temp.push_back(input[i]);
        while(checkPPAP(temp)) {
            for(int i=0; i<4; i++) {
                temp.pop_back();
            }
            temp.push_back('P');
        }
    }

    if(temp.size()==1 && temp[0]=='P') {
        cout<<"PPAP";
    }
    else {
        cout<<"NP";
    }
}