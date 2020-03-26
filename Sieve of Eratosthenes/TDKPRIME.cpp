#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> prime;
bool arr[90000001];
 
int seive(){
	int MAX = 90000000;
	arr[0] = arr[1] = true;
	
	for(int i=2; i*i<=MAX; i++){
		if (!arr[i]){
			for(int j=i*i; j<=MAX; j+=i){
					arr[j] = true;
				}
			}
		}
	
	for(int i=0; i<=90000000; i++){
		if (!arr[i]) { prime.push_back(i); }
		}
	return 0;
	}
 
int main(){
	
	int q;
	cin>>q;
	
	//cout<<"seive start"<<endl;
	seive();
	//cout<<"seive end()"<<endl;
	
	while (q--){
			int n;
			cin>>n;
			cout<<prime[n-1]<<endl;
		}
	return 0;
	}
 
