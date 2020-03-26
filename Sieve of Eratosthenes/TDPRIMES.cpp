#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> prime;
bool arr[100000001];
 
int seive(){
	int MAX = 100000000;
	arr[0] = arr[1] = true;
	
	for(int i=2; i*i<MAX; i++){
		if (!arr[i]){
			for(int j=i*i; j<MAX; j+=i){
					arr[j] = true;
				}
			}
		}
	
	int count = 0;
	for(int i=2; i<100000000; i++){
		
			if (!arr[i]) { 
				count += 1;
				if (count%100==1)
					printf("%d\n",i); 
				}
 
		}
	return 0;
	}
 
int main(){
	
	seive();
 
	return 0;
	}
