#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
ll st[1000000];
ll lazy[1000000];
 
ll update(ll si, ll ss, ll se, ll l, ll r){
	
	//cout<<ss<<" "<<se<<endl;
	if (ss>se){ return 0; }
	
	if (lazy[si]&1){
		st[si] = (se-ss+1) - st[si];
		if (ss!=se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
			}
		lazy[si] = 0;
		}
	
	if (ss > r || se < l){
		return 0;
		}
	
	if (ss >= l && se <= r){
		st[si] = (se-ss+1)-st[si];
		lazy[2*si+1] += 1;
		lazy[2*si+2] += 1;
		return 0;
		}
	
	ll mid=(ss+se)/2;
	update(2*si+1,ss,mid,l,r);
	update(2*si+2, mid+1,se,l,r);
	
	st[si] = st[2*si+1]+st[2*si+2];
	
	return 0;
	}
	
ll query(ll si, ll ss, ll se, ll l, ll r){
	//cout<<"query"<<endl;
	if (ss>se) { return 0; }
	
	if (lazy[si]&1){
		st[si] = (se-ss+1) - st[si];
		if (ss!=se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
			}
		lazy[si] = 0;
		}
		
		if (ss > r || se < l){
			return 0;
			}
		
		if (ss >= l && se<=r){
			return st[si];
			}
		
		ll mid=(ss+se)/2;
		ll a = query(2*si+1, ss, mid, l,r);
		ll b = query(2*si+2, mid+1,se,l,r);
		
		return a+b;
	}
 
int main(){
	
/*	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  */
	
	memset(st,0,sizeof(st));
	memset(lazy,0, sizeof(lazy));
	
	ll n,m;
	scanf("%lld%lld",&n,&m);
	//cin>>n>>m;
	while (m--){
		ll test, l, r;
		//cin>>test>>l>>r;
		scanf("%lld%lld%lld",&test,&l,&r);
		if (test){
			printf("%lld\n",query(0,0,n-1,l-1,r-1) );
			}
		else {
			update(0,0,n-1,l-1,r-1);
			}
		}
	}
