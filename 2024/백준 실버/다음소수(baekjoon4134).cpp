#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long input) {
    if(input<2) return false;

    double range=sqrt(input);
    for(int i=2; i<=range+1; i++) {
        if(input%i==0 && input!=i) {
            return false;
        }
    }
    return true;
}

int main() {
    int testCase;
    cin>>testCase;

    for(; testCase>0; testCase--) {
        long long input;
        cin>>input;

        while(true) {
            if(isPrime(input)) break;

            input++;
        }

        cout<<input<<"\n";
    }
}