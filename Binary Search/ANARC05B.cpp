#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	while (true){
		int n;
		cin>>n;
		
		vector<int> arr1(n);
		for(int i=0; i<n; i++){
			cin>>arr1[i];
			}
			
		if (n==0){ break; }
		
		int m;
		cin>>m;
		
		vector<int> arr2(m);
		for(int i=0; i<m; i++){
			cin>>arr2[i];
			}
		
		map<int,int> mp;
		int s = 0;
		for( int i : arr1){
			s += i;
			int index = lower_bound(arr2.begin(),arr2.end(), i) - arr2.begin();
			if (arr2[index] == i){
				mp[i] = s;
				s = 0;
				}
			}
		int arr1last = 0;
		if (s!=0){
			arr1last = s;
			}
			
		s = 0;
		int ans = 0;
		for( int i: arr2){
			s += i;
			if (mp.find(i)!=mp.end()){
				ans += max(mp[i], s);
				s = 0;
				}
			}
		int arr2last = 0;
		if (s!=0){
			arr2last = s;
			}
			
		//cout<<arr1last<<" -- "<<arr2last<<endl; 
			
		 ans += max(arr1last, arr2last);
			
		
		cout<<ans<<endl;
		}
	
	return 0;
	}
