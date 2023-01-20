#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101][101];
string input1, input2, input3;

bool allSame(char let1, char let2, char let3) {
    return ((let1==let2) && (let2==let3));
}

int getLCS(int ptr1, int ptr2, int ptr3) {
    if(ptr1==input1.size() || ptr2==input2.size() || ptr3==input3.size())
        return 0;

    int& ret=cache[ptr1][ptr2][ptr3];
    if(cache[ptr1][ptr2][ptr3]!=-1)
        return ret;
    char let1=input1[ptr1], let2=input2[ptr2], let3=input3[ptr3];
    ret=allSame(let1, let2, let3) ? 1+getLCS(ptr1+1, ptr2+1, ptr3+1) : 0;

    ret=max(ret, getLCS(ptr1+1, ptr2, ptr3));
    ret=max(ret, getLCS(ptr1, ptr2+1, ptr3));
    ret=max(ret, getLCS(ptr1, ptr2, ptr3+1));
    return ret;
}

int main() {
    cin>>input1>>input2>>input3;
    memset(cache, -1, sizeof(cache));
    cout<<getLCS(0, 0, 0);
}