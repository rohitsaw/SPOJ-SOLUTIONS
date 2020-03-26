#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
 
void powerset(ll arr[], ll a, ll b, vector<ll>& ans){
	
	ll n = (b-a);
	
	//cout<<"in index "<<a<<" "<<b<<endl;
	
	for(ll k=0; k<(1<<n); k++){
		ll s = 0;
		for(ll i=0; i<n; i++){
			if (k&(1<<i)){
				s += arr[a+i];
				}
			}
		//cout<<s<<endl;
		ans.push_back(s);
		}
	
	}
 
int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	
	ll arr[n];
	
	for(ll i=0; i<n; i++){
		cin>>arr[i];
		}
		
	vector<ll> left,right;
	powerset(arr, 0, n/2, left);
	powerset(arr, n/2, n, right);
	
	sort(right.begin(),right.end());
	
	ll ans = 0;
	for(ll i:left){
		ll p = a-i;
		ll q = b-i;
		
		ans += upper_bound(right.begin(), right.end(),q) - lower_bound(right.begin(),right.end(),p);
		
		}
		cout<<ans<<endl;
	
	return 0;
	}
