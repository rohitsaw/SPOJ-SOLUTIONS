#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
 
ll lf[100001];
int seive(){
	
	for(ll i=1; i<=100000; i++){
		lf[i] = -1;
		}
	
	for(ll i=2; i<=100000; i++){
		if (lf[i] == -1){
			for(ll j=i; j<=100000; j+=i){
				if (lf[j] == -1){
					lf[j] = i;
					}
				}
			}
		}
	return 0;
	}
	
ll nodiv(ll n){
	/* function to return number of divisor of n^2 */
	
	map<ll,ll> temp;
	while (n != 1){
		temp[lf[n]] += 1;
		n = n / lf[n];
		}
	ll ans = 1;
	for(auto i=temp.begin(); i!=temp.end(); i++){
		ans = ans * (2 * (*i).second + 1);
		}
	
	return ans;
	}
 
int main(){
	
	seive();
	map<ll, vector<ll> > mp;
	
	for(ll i=1; i<=100000; i++){
		mp[ nodiv(i) ].push_back(i*i);
		}
	
	ll t;
	cin>>t;
	
	while (t--){
		ll k,low,high;
		cin>>k>>low>>high;
		
		
		ll pos1 = lower_bound( mp[k].begin(), mp[k].end(), low) - mp[k].begin();
		ll pos2 = upper_bound( mp[k].begin(), mp[k].end(), high) - mp[k].begin();
		
		cout<< pos2-pos1 <<endl;
		
		}
	
	return 0;
	}
 
