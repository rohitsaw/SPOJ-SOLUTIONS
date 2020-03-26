#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
map<int, vector< pair<int,int> > > G;
 
int LCA[100010][int(log2(100010))];
int depth[100010];
ll dist[100010];
int maxN;
 
int dfs(int n, int par){
	
	LCA[n][0] = par;
	
	for(pair<int,int> child : G[n]){
		if (child.first != par){
			depth[child.first] = depth[n] + 1;
			dist[child.first] = dist[n] + child.second;
			dfs(child.first, n);
			}
		}
	return 0;
	}
 
int INIT(int n){
	
	
	depth[1] = 0;
	dist[1] = 0;
	
	dfs(1,-1);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=maxN; j++){
			if (LCA[i][j-1] != -1){
				int par = LCA[i][j-1];
				LCA[i][j] = LCA[par][j-1];
				}
			}
		}
	
	return 0;
	}
 
int lca(int a, int b){
	
	if (depth[a] > depth[b]){ swap(a,b); }
	int d = depth[b] - depth[a];
	
	while (d>0){
		int i = log2(d);
		b = LCA[b][i];
		d -= (1<<i);
		}
	
	if (a==b){
		return a;
		}
	
	for(int i=maxN; i>=0; i--){
		if (LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]){
			a = LCA[a][i];
			b = LCA[b][i];
			}
		}
	
	return LCA[a][0];
	}
	
int getKth(int k, int n){
	
	while (k>0){
		int i = log2(k);
		n = LCA[n][i];
		k -= (1<<i);
		}
	
	return n;
	}
 
int main(){
	int t;
	cin>>t;
	
	while (t--){
		
		
		G.clear();
		memset(LCA,-1,sizeof(LCA));
		memset(depth,0,sizeof(depth));
		memset(dist,0,sizeof(dist));
		
		int n;
		cin>>n;
		
		maxN = log2(n);
		
		for(int i=1; i<=n-1; i++){
			int a,b,c;
			cin>>a>>b>>c;
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
			}
			
		INIT(n);
		string s;
	
		while (cin>>s){
			if (s == "DONE"){
				break;
				}
			if (s == "DIST"){
				int a,b;
				cin>>a>>b;
				
				int mid = lca(a,b);
				int distance = dist[a] + dist[b] - 2*dist[mid];
				cout<<distance<<endl;
				
				}
			else if (s == "KTH"){
				int a,b,k;
				cin>>a>>b>>k;
				int mid = lca(a,b);
				int d1 = depth[a]-depth[mid];
				int d2 = depth[b] - depth[mid];
				k -= 1;
				if (k<=d1){
					//cout<<"in first"<<endl;
					cout<<getKth(k,a)<<endl;
					}
				else{
					int k1 = d1+d2-k;
					//cout<<"in second "<<k1<<endl;
					cout<<getKth(k1,b)<<endl;
					}
				}
			}
		}
	
	return 0;
	}
