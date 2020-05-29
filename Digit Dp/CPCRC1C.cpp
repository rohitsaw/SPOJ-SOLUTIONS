#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll arr[100];


ll dp[12][110][2];


ll sum(ll pos, ll n, ll s, bool flag){
	
	
	if (dp[pos][s][flag] != -1)
		return dp[pos][s][flag];
	
	if (pos>n) return s;
	
	ll limit;
	if (!flag)
		limit = arr[pos];
	else
		limit = 9;
	
	ll ans = 0;
	for(ll i=0; i<=limit; i++){
		if (flag || i < limit)
			ans += sum(pos+1, n, s+i, true);
		else
			ans += sum(pos+1, n, s+i, false);
		}
		
	dp[pos][s][flag] = ans;
	return ans;
	}

int main(){
	
	string a,b;
	while (true){
		cin>>a>>b;
		
		if (a == "-1" && b == "-1")
			break;
		
		// ans = sum(b)-sum(a-1)
		
		a = to_string(stoi(a)-1);
		for(ll i=0; i<(ll)a.size(); i++)
			arr[i+1] = a[i]-'0';
		
		memset(dp,-1,sizeof(dp));
		ll k1 = sum(1,(ll)a.size(), 0, false);
		
		
		
		for(ll i=0; i<(ll)b.size(); i++)
			arr[i+1] = b[i]-'0';
			
		memset(dp,-1,sizeof(dp));
		ll k2 = sum(1,(ll)b.size(), 0, false);
		
		cout<<k2-k1<<endl;
		
		}
	
	return 0;
	}
