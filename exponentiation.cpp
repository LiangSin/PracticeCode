#include<bits/stdc++.h>
using namespace std;

long long expo(int base, int power){
	if(power==0)
		return 1;
	if(power%2==2){
		long long tmp = expo(base,power/2);
		return tmp*tmp;
	}
	else{
		return base*expo(base,power-1);
	}
}

int main(){
	int base,power;
	cout << "input base and power: ";
	cin >> base >> power;
	cout << "the answer is " << expo(base,power);
}