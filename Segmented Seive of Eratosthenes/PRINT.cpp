#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define MAX 1000000
 
vector<ll> primes;
 
int seive(){
	
	vector<bool> isPrime(MAX+1,true);
	
	for(ll i=2; i*i<=MAX; i++){
		if (isPrime[i]){
			for(ll j=i*i; j<=MAX; j+=i){
				isPrime[j] = false;
				}
			}
		}
	for(ll i=2; i<=MAX; i++){
		if (isPrime[i])
			primes.push_back(i);
		}
	return 0;
	}
 
 
int main(){
	
	seive();
	
	ll t;
	cin>>t;
	
	while (t--){
		
		ll l,r;
		//cin>>l>>r;
		scanf("%lld%lld",&l,&r);
		
		
		vector<bool> isPrime(r-l+1,true);
		
		//for(ll i=0; primes[i]*primes[i] <= r; i++){
		for(auto cp : primes){
			
			if (cp*cp > r)
				break;
									
			ll base = (l/cp)*cp;
			if (base < l)
				base = base + cp;
				
			for(ll j=base; j<=r; j+=cp){
				isPrime[j-l] = false;
				}
			
			if (base == cp)
				isPrime[cp-l] = true;
			
			}
		
		for(ll i=0; i<=r-l; i++){
			if (isPrime[i]){
				//cout<<i+l<<endl;
				printf("%lld\n",i+l);
				}
			}		
		}
		
return 0;
}
