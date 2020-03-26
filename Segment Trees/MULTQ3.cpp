#include <bits/stdc++.h>
 
using namespace std;
 
struct node{
	int rem0=0, rem1=0, rem2=0;
	};
	
node st[4*1000000];
int lazy[4*1000000];
 
 
int rotate(node& a, int limit){
	
	limit = limit%3;
	
	while (limit--){
		int temp;
		temp = a.rem1;
		a.rem1 = a.rem0;
		a.rem0 = a.rem2;
		a.rem2 = temp;
	}
	return 0;
	}
 
int build(int si, int ss, int se){
	
	if (ss==se){
		st[si].rem0 = 1;
		st[si].rem1 = 0;
		st[si].rem2 = 0;
		return 0;
		}
		
	int mid = (ss+se)/2;
	build(2*si+1, ss, mid);
	build(2*si+2,mid+1, se);
	
	st[si].rem0 = st[2*si+1].rem0 + st[2*si+2].rem0;
	st[si].rem1 = st[2*si+1].rem1 + st[2*si+2].rem1;
	st[si].rem2 = st[2*si+1].rem2 + st[2*si+2].rem2;
	
	return 0;
	}
 
node query(int si, int ss, int se, int l, int r){
	
	if (ss>se) {
		node temp;
		return temp;
		 }
	
	if (lazy[si]!=0){
		rotate(st[si],lazy[si]);
		if (ss!=se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
			}
		lazy[si] = 0;
		}
	
	if (ss>r || se<l){
		node temp;
		return temp;
		}
	
	if (ss>=l && se<=r){
		return st[si];
		}
	
	int mid = (ss+se)/2;
	node left = query(2*si+1,ss,mid,l,r);
	node right = query(2*si+2,mid+1,se,l,r);
	
	node temp;
	
	temp.rem0 = left.rem0 + right.rem0;
	temp.rem1 = left.rem1 + right.rem1;
	temp.rem2 = left.rem2 + right.rem2;
	
	return temp;
	}
	
int update(int si, int ss, int se, int l, int r){
	
	if (ss>se) { return 0; }
	
	if (lazy[si]!=0){
		rotate(st[si],lazy[si]);
		if (ss!=se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
			}
		lazy[si] = 0;
		}
	
	if (ss > r || se < l){
		return 0;
		}
	
	if (ss >= l && se <= r){
		rotate(st[si],1);
		if (ss != se){
			lazy[2*si+1] += 1;
			lazy[2*si+2] += 1;
			}
		return 0;
		}
	
	int mid = (ss+se)/2;
	
	update(2*si+1,ss,mid,l,r);
	update(2*si+2, mid+1,se,l,r);
	
	st[si].rem0 = st[2*si+1].rem0 + st[2*si+2].rem0;
	st[si].rem1 = st[2*si+1].rem1 + st[2*si+2].rem1;
	st[si].rem2 = st[2*si+1].rem2 + st[2*si+2].rem2;
	
	return 0;
	}
 
int main(){
	
/*	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  */
	
	int n,q;
	//cin>>n>>q;
	scanf("%d%d",&n,&q);
	
	build(0,0,n-1);
	
	while (q--){
		int test,a,b;
		//cin>>test>>a>>b;
		scanf("%d%d%d",&test,&a,&b);
		if (test){
			printf("%d\n", query(0,0,n-1,a,b).rem0 );
			}
		else { 
			update(0,0,n-1,a,b);
			}
		}
	return 0;
	}
