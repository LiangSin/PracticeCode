#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void product(ll A[2][2], ll B[2][2], ll rtn[2][2]){
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			rtn[i][j] = A[i][i]*B[i][j] + A[i][1-i]*B[1-i][j];
}

void expo(ll A[2][2], int power, ll rtn[2][2]){
	if(power<=1){
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				rtn[i][j] = A[i][j];
	}
	else if(power%2==0){
		ll B[2][2];
		expo(A,power/2,B);
		product(B,B,rtn);
	}
	else{
		ll B[2][2];
		expo(A,power-1,B);
		product(A,B,rtn);
	}
}

int main(){
	ll A[2][2] = {{1,1},{1,0}};
	int n;
	cin >> n;
	if(n>0){
		ll ans[2][2];
		expo(A,n-1,ans);
		cout << "f(" << n << ") is " << ans[0][0];
	}
}