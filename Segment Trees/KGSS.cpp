#include <bits/stdc++.h>
 
#define N 1000000
#define ll long long int
using namespace std;
 
struct node{
	ll m1=-1,m2=-1;
	};
	
node st[4*N];
ll arr[N];
 
int build(ll si, ll ss, ll se){
	
	if (ss==se){
		st[si].m1 = arr[ss];
		st[si].m2 = -1;
		return 0;
		}
	
	ll mid = (ss+se)/2;
	build(2*si+1,ss,mid);
	build(2*si+2,mid+1,se);
	
	vector<ll> temp = {st[2*si+1].m1, st[2*si+1].m2, st[2*si+2].m1, st[2*si+2].m2};
	
	sort(temp.begin(), temp.end());
	st[si].m1 = *temp.rbegin();
	st[si].m2 = *(++temp.rbegin());
	return 0;
	}
 
int update(ll si, ll ss, ll se, ll i, ll x){
	
	if (i<ss || i>se){
		return 0;
		}
	
	else if (ss == i && se == i){
		st[si].m1 = x;
		return 0;
		}
		
	else{
		ll mid = (ss+se)/2;
			update(2*si+1, ss, mid, i, x);
			update(2*si+2, mid+1, se, i, x);
		}
		
	vector<ll> temp = {st[2*si+1].m1, st[2*si+1].m2, st[2*si+2].m1, st[2*si+2].m2};
	sort(temp.begin(),temp.end());
	st[si].m1 = *temp.rbegin();
	st[si].m2 = *(++temp.rbegin());
 
	return 0;
	}
 
node query(ll si, ll ss, ll se, ll l, ll r){
	//cout<<"in query "<<ss<<" "<<se<<endl;
	
	node temp;
	
	if (ss>r || se<l){
		return temp;
		}
	if (ss>=l && se<=r){
		return st[si];
		}
		
	ll mid = (ss+se)/2;
	
	node a1 = query(2*si+1,ss,mid,l,r);
	node a2 = query(2*si+2,mid+1,se,l,r);
	
	vector<ll> te = {a1.m1, a1.m2, a2.m1, a2.m2};
	sort(te.begin(), te.end());
	
	temp.m1 = *te.rbegin();
	temp.m2 = *(++te.rbegin());
	
	
	return temp;
	
	}
	
int main(){
	
	ll n;
	cin>>n;
	
	for(ll i=0; i<n; i++){
		cin>>arr[i];
		}
	
	build(0,0,n-1);	
	
	ll q;
	cin>>q;
	
	while (q--){
		char ch;
		cin>>ch;
		if (ch == 'U'){
			ll i,x;
			cin>>i>>x;
			i -= 1;
			update(0,0,n-1,i,x);
			}
		else if (ch == 'Q'){
			ll x,y;
			cin>>x>>y;
			x -= 1;
			y -= 1;
			node temp = query(0,0,n-1,x,y);
			cout<<temp.m1+temp.m2<<endl;
			}
		}
		
	return 0;
	}
