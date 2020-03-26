#include <bits/stdc++.h>
 
using namespace std;
 
 
struct node{
	int sum=INT_MIN;
	int prefix=INT_MIN;
	int suffix=INT_MIN;
	int max=INT_MIN;
	};
 
int arr[50010];
node st[4*50010];
 
int build(int si, int ss, int se){
	if (ss==se){
		st[si].max=arr[ss];
		st[si].prefix=arr[ss];
		st[si].suffix=arr[ss];
		st[si].sum=arr[ss];
		return 0;
		}
	int mid = (ss+se)/2;
	build(2*si+1,ss,mid);
	build(2*si+2,mid+1,se);
	
	node left = st[2*si+1];
	node right = st[2*si+2];
	
	st[si].sum = left.sum + right.sum;
	st[si].prefix = max(left.prefix, left.sum+right.prefix);
	st[si].suffix = max(right.suffix, right.sum+left.suffix);
	
	st[si].max = max(st[si].prefix,max(st[si].suffix,max(left.max,max(right.max,left.suffix+right.prefix))));
	
	return 0;
	}
 
node query(int si, int ss, int se, int l, int r){
	
	// completely outside
	if (ss > r || se < l){
		node temp;
		return temp;
		}
	
	// completely inside
	if (ss >= l && se <= r){
		return st[si];
		}
		
	// partially inside and outside
	int mid = (ss+se)/2;
	
	if (r<=mid){
		return query(2*si+1, ss, mid, l, r);
		}
	if (l>mid){
		return query(2*si+2, mid+1, se, l, r);
		}
		
	node left = query(2*si+1, ss, mid, l, r);
	node right = query(2*si+2, mid+1, se, l, r);
	
	node result;
	result.sum = left.sum+right.sum;
	result.prefix = max(left.prefix, left.sum+right.prefix);
	result.suffix = max(right.suffix, right.sum+left.suffix);
	
	result.max = max(result.prefix,max(result.suffix,max(left.max,max(right.max,left.suffix+right.prefix))));
	return result;
	
	}
 
int main(){
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		}
		
	build(0,0,n-1);
	
/*	for(int i=0; i<15; i++){
		cout<<st[i].max<<" "<<st[i].prefix<<" "<<st[i].suffix<<" "<<st[i].sum<<endl;
		}    */
	
	int m;
	cin>>m;
	
	int l,r;
	for(int i=0; i<m; i++){
		cin>>l>>r;
		cout<<query(0,0,n-1,l-1,r-1).max<<endl;
		}
	return 0;
	}
