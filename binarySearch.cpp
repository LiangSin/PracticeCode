#include<bits/stdc++.h>
#define MAX 12
using namespace std;
void vprint(auto l, auto r){while(l<r) cerr << *l << " \n"[next(l)==r], ++l;}

int main(){
	int n;
	int vec[MAX];
	cout << "input the size of the vector: ";
	cin >> n;
	cout << "input the vector: ";
	for(int i=0; i<n; i++){
		cin >> vec[i];
	}
	sort(vec,vec+n);
	cout << "sorted: ";
	vprint(vec, vec+n);

	int target;
	cout << "input your target: ";
	cin >> target;

	int left,mid,right;
	left = 0;
	right = n;
	mid = (left+right)/2;
	
	while(left<right-1){
		if(vec[mid]<=target)
			left = mid;
		else
			right = mid;
		mid = (left+right)/2;
		if(vec[left]==target)
			break;
	}

	if(vec[left]==target)
		cout << "found " << target << " at index " << left+1 << '\n';
	else
		cout << "not found\n";
}