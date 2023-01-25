#include<bits/stdc++.h>
using namespace std;

int main(){
	int target=-1;
	while(target<=1){
		cout << "Please enter a number greater than 1: ";
		cin >> target;
	}

	int factor=2;
	bool isPrime=1;
	while(factor*factor<target && isPrime){
		if(target%factor==0)
			isPrime = 0;
		else
			factor++;
	}

	if(isPrime)
		cout << target << " is a prime number.\n";
	else
		cout << target << " is not a prime number.\n";
}