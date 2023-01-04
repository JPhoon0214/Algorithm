#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isAvail=true;

long long calRet(string input) {
    if(input.size()==0)
        return 1;
    
    stack<char> lets;
    int index=0;
    long long ret=0;
    
    while(index<input.size()) {
        long long smallRet=input[index]=='(' ? 2 : 3;
        lets.push(input[index++]);
        int begin=index;
        int countLet=0;
        while(index<input.size() && !lets.empty()) {
            char currLet=input[index];
            if(currLet=='(' || currLet=='[') {
                lets.push(currLet);
            }
            else {
                if(currLet==')' && lets.top()=='(') {
                    lets.pop();
                }
                else if(currLet==']' && lets.top()=='[') {
                    lets.pop();
                }
                else {
                    isAvail=false;
                }
            }
            countLet++;
            index++;
        }
        if(!lets.empty()) {
            isAvail=false;
        }
        
        smallRet*=calRet(input.substr(begin, countLet-1));
        ret+=smallRet;
    }
    return ret;
}

int main() {
    string input;
    cin>>input;
    long long ret=calRet(input);;
    if(isAvail)
        cout<<ret;
    else
        cout<<0;
}