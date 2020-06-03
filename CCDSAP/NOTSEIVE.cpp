#include <bits/stdc++.h>

using namespace std;

#define ll long long int

const long long int MAX = 100000;
vector<ll> primes;
vector<ll> primesquare;




int seive(){
	
	vector<bool> prime(MAX+1,true);
	
	for(ll i=2; i*i<=MAX; i++){
		if (prime[i]){
			for(ll j=i*i; j<=MAX; j+=i){
				prime[j] = false;
				}
			}
		}
	for(ll i=2; i<=MAX; i++){
		if (prime[i]){
			primes.push_back(i);
			primesquare.push_back(i*i);
			}
		}
	return 0;
	}
	
ll power(ll a, ll b, ll m){
	ll res = 1;
	while (b){
		if (b&1)
			b -= 1, res = res*a % m;
		b = b/2;
		a = a*a % m;
		}
	return res;
	}
	
bool miillerTest(ll d, ll n) 
{ 
    ll a = 2 + rand() % (n - 4); 
  
    ll x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 

    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
    return false; 
} 
	
bool isPrime(int n, int k) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
  
    int d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
  
    for (int i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
    return true; 
} 


int main(){
	
	seive();
	int t;
	cin>>t;
	
	while (t--){
		ll l,r;
		cin>>l>>r;
		
/*		vector<bool> temp(r-l+1,true);
		vector<ll> segprimes;
		
		for(auto& prime : primes){
			
			if (prime*prime > r)
				break;
			
			ll base = (l/prime)*prime;
			if (base < l)
				base = base + prime;
			
			for(ll i=base; i<=r; i+=prime)
				temp[i-l] = false;
			
			if (base == prime)
				temp[base-l] = true;
			
			}
		for(ll i=0; i<=r-1; i++){
			if (temp[i])
				segprimes.push_back(i+l);
			}
*/
		ll ans = 0;
		for(ll i=l; i<=r; i++){
			ll n = i;
			
			ll nf = 1;
			ll mm = INT_MAX;
			for(auto& prime : primes){
				if (prime*prime*prime > n)
					break;
				ll cnt = 0;
				while (n%prime == 0){
					cnt += 1;
					n = n/prime;
					}
				nf = nf*(cnt+1);
				mm = (cnt>0 && cnt<mm)?cnt:mm;
				}
				
			if (n!=1){
				if (isPrime(n, 5))
					nf = nf*2, mm = (1<mm)?1:mm ;
				else if (*lower_bound(primesquare.begin(), primesquare.end(), n) == n)
					nf = nf * 3, mm = (2<mm)?2:mm ;
				else{
					nf = nf * 4, mm = (1<mm)?1:mm ;
					}
				//cout<<"for "<<i<<" "<<nf<<" "<<mm<<endl;
			}
			ans += nf/(mm+1) ;
			
			}
		cout<<ans<<endl;
		
		}
	
	return 0;
	}
