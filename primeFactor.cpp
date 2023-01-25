#include<bits/stdc++.h>
using namespace std;

int main(){
	int target=-1;
	while(target<=1){
		cout << "Please enter a number greater than 1: ";
		cin >> target;
	}

	int factor=2,copy;
	bool isPrime=1;
	set<int> primeFactor;
	copy = target;
	while(copy>1){
		if(factor*factor>target && isPrime)
			break;
		while(copy%factor==0){
			primeFactor.insert(factor);
			isPrime = 0;
			copy/=factor;
		}
		factor++;
	}
	if(isPrime)
		primeFactor.insert(target);

	cout << target << " has the prime factor(s): ";
	for(auto pf : primeFactor)
		cout << pf << " ";
}