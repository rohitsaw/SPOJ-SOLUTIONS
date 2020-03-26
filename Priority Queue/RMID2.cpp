#include <bits/stdc++.h>
 
using namespace std;
 
#define lint long long int
 
int main(){
/*	ios_base::sync_with_stdio(false);
	cin.tie(NULL); */
	
	lint t;
	scanf("%lld",&t);
	
	
	while (t--){
		priority_queue <lint> max_heap;
		priority_queue <lint, vector<lint>, greater<lint> > min_heap;
		
		lint n;
		while (true){
			
			scanf("%lld",&n);
			if (n==0){ break; }
			
			if (n==-1){
				if (max_heap.size() >= min_heap.size()){
					lint temp = max_heap.top();
					max_heap.pop();
					//cout<<temp<<endl;
					printf("%lld\n",temp);
					}
				else{
					lint temp = min_heap.top();
					min_heap.pop();
					//cout<<temp<<endl;
					printf("%lld\n",temp);
					}
				
				}
			else if ( max_heap.empty() || max_heap.top()>n){
				max_heap.push(n);
				}
			else {
				min_heap.push(n);
				} 
			
			lint smax  = (lint)max_heap.size();
			lint smin = (lint)min_heap.size();
			
			
			if ((smax-smin) >= 2){
				lint temp = max_heap.top();
				max_heap.pop();
				min_heap.push(temp);
				}
			//cout<<(int)min_heap.size()-(int)max_heap.size()<<endl;
			
			else if (smin-smax >=2 ){
				lint temp = min_heap.top();
				min_heap.pop();
				max_heap.push(temp);
				}  
			}
		}
	return 0;
	}
