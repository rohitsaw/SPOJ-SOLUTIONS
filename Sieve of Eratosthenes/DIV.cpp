#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
 
ll lf[1000001];
int seive(){
	
	for(ll i=1; i<=1000000; i++){
		lf[i] = -1;
		}
	
	for(ll i=2; i<=1000000; i++){
		if (lf[i] == -1){
			for(ll j=i; j<=1000000; j+=i){
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
		ans = ans * ( (*i).second + 1);
		}
	
	return ans;
	}
 
vector<ll> primeFact(ll k){
	
	vector<ll> temp;
	while (k!=1){
		temp.push_back(lf[k]); 
		k = k/lf[k];
		
		}
	return temp;
	
	}
 
bool is_mul_prime(vector<ll>& te){
	if ((int)te.size()!=2){
		return false;
		}
	ll a = te[0];
	ll b = te[1];
	if (a!=b && lf[a]==a && lf[b]==b){
		return true;
		}
	return false;
	}
 
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	seive();
	
	ll cnt = 0;
	for(ll i=1; i<=1000000; i++){
		ll k = nodiv(i);
		vector<ll> fact = primeFact(k);
		
		if (is_mul_prime(fact)){
			cnt += 1;
			if (cnt%9==0){
				cout<<i<<endl;
				}
			}
			
		}  
			
	return 0;
	}
