#include <bits/stdc++.h>

using namespace std;


struct FenwickTree{
	
	struct node{
		int k;
		vector<int> rem;
		node(int k) : k(k) {
			rem.assign(k,0);
			}
		};
		
	int n,k;
	vector<node> bit;
	vector<int> oarr;
	
	FenwickTree(int n, int k){
		this->n = n+1;
		this->k = k;
		bit.assign(this->n, node(k));
		oarr.assign(n,0);
		}
		
	int build(vector<int>& arr){
		for(int i=0; i<(int)arr.size(); i++){
			oarr[i] = arr[i];
			for(int idx=i+1; idx<n; idx += idx & (-idx)){
				bit[idx].rem[ arr[i]%k ] += 1;
				}
			}
		return 0;
		}
		
	int update(int idx, int val){
		
		int preV = oarr[idx];
		int newV = preV+val;
				
		for(int i=idx+1; i<n; i += i&(-i)){
				bit[i].rem[preV%k] -= 1;
				bit[i].rem[newV%k] += 1;
			}
		oarr[idx] = newV;
		
		return 0;
		}
		
	int sum(int idx, int req){
		int res = 0;
		for(idx=idx+1; idx>0; idx -= idx & (-idx)){
			res += bit[idx].rem[req];
			}
		return res;
		}
	
	int sum(int l,int r, int req){
		return sum(r,req)-sum(l-1,req);
		}  
	
	};

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,q,k;
	cin>>n>>q>>k;
	
	FenwickTree tree(n, k);
	vector<int> arr(n,0);
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
		}
		
	tree.build(arr);
		
	for(int i=0; i<q; i++){
		int tb;
		cin>>tb;
		if(tb==1){
			int p, val;
			cin>>p>>val;
			tree.update(p-1,val);
			}
		else{
			int l,r,rem;
			cin>>l>>r>>rem;
			int ans = tree.sum(l-1,r-1,rem);
			cout<<ans<<endl;
			}
		}	
	
	
	return 0;
	}
