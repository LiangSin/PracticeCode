//AP325 P-2-9
#include<bits/stdc++.h>
#define N 37
using namespace std;
typedef long long ll;

ll find(int num[N], int len, map<ll,ll> &mp, int now, ll ans, int p){
	if(now==len){
		if(mp.find(ans)==mp.end())
			mp[ans] = 1;
		else{
			mp[ans]++;
			mp[ans] = mp[ans]%p;
		}
		if(ans%p==1)
			return 1;
		else
			return 0;
	}
	ll rtn=0;
	rtn = (rtn + find(num, len, mp, now+1, ans, p))%p;
	rtn = (rtn + find(num, len, mp, now+1, ans*num[now]%p, p))%p;
	return rtn;
}

ll exp(int base, int m, int p){
	if(m==0)
		return 1;
	if(m%2!=0)
		return (exp(base,m-1,p)*base)%p;
	else{
		ll rtn = exp(base,m/2,p)%p;
		return (rtn*rtn)%p;
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n,p;
	int input[N];
	cin >> n >> p;
	for(int i=0; i<n; i++){
		cin >> input[i];
		input[i] = input[i]%p;
	}

	map<ll,ll> m1,m2;
	ll cnt=0;
	cnt = (cnt + find(input, n/2, m1, 0, 1, p))%p;
	cnt = (cnt + find(input+n/2, n-n/2, m2, 0, 1, p))%p;
	m1[1]--, m2[1]--, cnt-=2;
	if(cnt<0)
		cnt += p;

	for(auto a:m1){
		ll target = exp(a.first,p-2,p);
		if(m2.find(target)!=m2.end())
			cnt = (cnt + a.second*m2[target])%p;
	}

	cout << cnt;
}