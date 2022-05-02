#include <iostream>
#include <vector>

using namespace std;
int space[10001];
int n_list[100];

int main() {
	int n, k;
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		cin >> n_list[i];
	}
	
	for(int j=0; j<k+1; j++) {
		space[j] = 0;
	}
	
	for(int i=1; i<n+1; i++) {
		int price = n_list[i-1];
		for(int j=0; j<k+1; j++) {
			if(j==0)
				space[j] = 1;
			if(j >= price)
				space[j] += space[j-price];
		}
	}
	cout << space[k];
}