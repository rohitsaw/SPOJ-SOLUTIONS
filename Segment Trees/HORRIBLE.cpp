#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
ll st[4*1000100];
ll lazy[4*1000100];
 
 
ll update(ll si, ll ss, ll se, ll l, ll r, ll v){
	
	//cout<<ss<<" "<<se<<" "<<l<<" "<<r<<endl;
	
	if (ss>se) { return 0; }
	
	// checking lazy
	if (lazy[si]!=0){
		st[si] += lazy[si]*(se-ss+1);
		// checking leaves node
		if (ss!=se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
			}
		lazy[si] = 0;
		}
	
	// completely outside
	if (ss > r || se < l){
		//cout<<"com outside"<<ss<<" "<<se<<endl;
		return 0;
		}
	
	// completely inside
	if (ss>=l && se<=r){
		//cout<<"com inside"<<ss<<" "<<se<<endl;
		
		st[si] += v*(se-ss+1);
		lazy[2*si+1] += v;
		lazy[2*si+2] += v;
		return 0;
		}
		
	// partially inside
	ll mid = (ss+se)/2;
	
	
	update(2*si+1, ss,mid,l,r,v);
	update(2*si+2,mid+1,se,l,r,v);
	
	
	
	st[si] = st[2*si+1]+st[2*si+2];
	return 0;
	}
 
 
/* int print(int a, int b){
	
	b *= 2;
	cout<<"print st"<<endl;
	for(int i=0; i<=b; i++){
		cout<<st[i]<<" ";
		}
	cout<<endl;
	cout<<"print lazy"<<endl;
	for(int i=0; i<=b; i++){
		cout<<lazy[i]<<" ";
		}
	cout<<endl;
	
	return 0;
	}  */
 
ll query(ll si, ll ss, ll se, ll l, ll r){
	
	//cout<<ss<<" "<<se<<" "<<l<<" "<<r<<endl;
	
	// checking lazy
	if (lazy[si]!=0){
		st[si] += lazy[si]*(se-ss+1);
		// checking leaves node
		if (ss!=se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
			}
		lazy[si] = 0;
		}
	
	// completely outside
	if (ss > r || se < l){
		//cout<<"outside "<<ss<<" "<<se<<endl;
		return 0;
		}
		
	// completely inside
	if (ss >= l && se <= r){
		//cout<<"inside "<<ss<<" "<<se<<endl;
		return st[si];
		}
	
	//cout<<"partially "<<ss<<" "<<se<<endl;
	// partially inside
	ll mid = (ss+se)/2;
	ll a = query(2*si+1, ss,mid,l,r);
	ll b = query(2*si+2,mid+1,se,l,r);
	
	return a+b;
	
	}
 
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int t;
	cin>>t;
	
	while (t--){
		memset(st,0,sizeof(st));
		memset(lazy,0,sizeof(lazy));
		
		int n,c;
		cin>>n>>c;
		while (c--){
			int test;
			cin>>test;
			if (test==1){
				ll p,q;
				cin>>p>>q;
				p -= 1;
				q -= 1;
				cout<< query(0,0,n-1, p,q)<<endl;
				//print(0,n-1);
				}
			else {
				ll p,q,v;
				cin>>p>>q>>v;
				p -= 1;
				q -= 1;
				update(0,0,n-1,p,q,v);
				//print(0,n-1);
				}
			}
		}
	return 0;
	}
