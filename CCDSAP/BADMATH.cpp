#include <bits/stdc++.h>

using namespace std;

int n,m;
string s;

int bpow(int a, int b){
	int res = 1;
	
	while (b>0){
		if (b&1)
			res = res*a % m;
		b = b/2;
		a = a*a % m;
		}
	return res;
	}


int f(int pos, int temp){
	
	//cout<<"upto pos "<<pos-1<<" res is "<<temp<<endl;
	
	if (pos >= n){
		if (temp%m == 0)
			return 1;
		else
			return 0;
		}
		
	if (s[pos] != '_')
		return f(pos+1, (temp + (s[pos]-'0')*bpow(2,pos))%m);
	else{
		return f(pos+1, temp%m ) + f(pos+1, (temp + bpow(2,pos))%m) ;
		}
	
	
	}

int main(){
	int t;
	cin>>t;
	
	while (t--){
		
		s.clear();
		
		cin>>n>>m;
		cin>>s;
		
		reverse(s.begin(), s.end());
		
		int ans = f(0,0);
		cout<<ans<<endl;
		
		}
	
	return 0;
	}
