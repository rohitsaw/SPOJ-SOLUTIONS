#include <bits/stdc++.h>

using namespace std;


vector<int> arr;

struct SegmentTree{
	
	struct node{
		vector<int> rem;
		int k;
		node(int k) : k(k) {
			rem.assign(k,0);
			}
		};
	
	vector<node> st;
	int k;
	
	SegmentTree(vector<int>& arr, int k): k(k){
		st.assign(4*(int)arr.size(), node(k) );
		build(0, 0, (int)arr.size()-1);
		}
		
	int rotate(vector<int>& arr, int p){
		int n = (int)arr.size();
		for(int j=0; j<p; j++){
			int temp = arr[n-1];
			for(int i=n-2; i>=0; i--){
				arr[i+1] = arr[i]; 
			}
			arr[0] = temp;
		}
	return 0;
	}	
	
	
	int build(int si, int ss, int se){
		if (ss==se){
			st[si].rem[arr[ss]%k] += 1;
			return 0;
			}
		int mid = (ss+se)/2;
		build(2*si+1,ss, mid);
		build(2*si+2,mid+1,se);
		
		for(int i=0; i<k; i++){
			st[si].rem[i] = st[2*si+1].rem[i] + st[2*si+2].rem[i];
			}
		return 0;
		}
		
	int update(int si, int ss, int se, int pos, int val){
		if (ss > pos || se < pos){
			return 0;
			}
		if (ss==pos && se==pos){
			int rr = val%k;
			rotate(st[si].rem, rr);
			return 0;
			}
		
		int mid = (ss+se)/2;
		
		if (pos <= mid)
			update(2*si+1,ss,mid,pos,val);
		else
			update(2*si+2,mid+1,se,pos,val);
		
		for(int i=0; i<k; i++){
			st[si].rem[i] = st[2*si+1].rem[i] + st[2*si+2].rem[i];
			}
		return 0;
		}
		
	int query(int si, int ss, int se, int l, int r, int rrem){
		
		if (ss > r || se < l){
			return 0;
			}
		if (ss >= l && se <= r){
			return st[si].rem[rrem];
			}
			
		int mid = (ss+se)/2;
		int a = query(2*si+1,ss,mid,l,r,rrem);
		int b = query(2*si+2,mid+1,se,l,r,rrem);
		
		return a+b;
		}
	
	};

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,q,k;
	cin>>n>>q>>k;
	
	arr.assign(n,0);
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	SegmentTree tree(arr,k);
	
	
	for(int i=0; i<q; i++){
		int tb;
		cin>>tb;
		if(tb==1){
			int p,val;
			cin>>p>>val;
			tree.update(0,0,n-1,p-1,val);
			}
		else{
			int l,r,rem;
			cin>>l>>r>>rem;
			int ans = tree.query(0,0,n-1,l-1,r-1, rem);
			cout<<ans<<endl;
			}
		}
	
	return 0;
	}
