#include <iostream>

using namespace std;

void printABNum(int aNum, int bNum, int remain) {
    if(remain==0) {
        cout<<aNum<<" "<<bNum;
        return;
    }
    printABNum(bNum, aNum+bNum, remain-1);
}

int main() {
    int k;
    cin>>k;
    printABNum(1, 0, k);
}