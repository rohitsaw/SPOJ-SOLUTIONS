#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin>>n;
	
	vector<int> s;
	int temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		s.push_back(temp);
		}
		
	map<int,int> arr1,arr2;
	for(int a=0; a<n; a++)
		for(int b=0; b<n; b++)
			for(int c=0; c<n; c++){
				arr1[ (s[a]*s[b])+s[c]  ] += 1;
				//cout<<"found abc"<<endl; 
				}
	
	for(int d=0; d<n; d++)
		for(int e=0; e<n; e++)
			for(int f=0; f<n; f++)
				if (s[d]!=0) {
					arr2[ (s[e]+s[f])*s[d] ] += 1;
					//cout<<"found def"<<endl; 
					}
		
	long long int ans = 0;
	for(auto it=arr1.begin(); it!=arr1.end(); it++){
		if (arr2.find( (*it).first ) != arr2.end()){
			ans += (*it).second * arr2[(*it).first];
			}
		}
	
	
	cout<<ans<<endl;
		
	return 0;
	}
