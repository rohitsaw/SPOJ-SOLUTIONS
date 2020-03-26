#include <bits/stdc++.h>
 
using namespace std;
 
map<int, vector<int> > G;
 
int main(){
	int n,k;
	cin>>n>>k;
	
	map<int,int> indeg;
	
	for(int i=1; i<=k; i++){
		int w;
		cin>>w;
		for(int j=1; j<=w; j++){
			int v;
			cin>>v;
			G[i].push_back(v);
			indeg[v] += 1;
			}
		}
	
	priority_queue<int, vector<int>, greater<int> > p;
	
	for(int i=1; i<=n; i++){
		if (indeg[i]==0){
			p.push(i);
			}
		}
	
	/*for(auto it=indeg.begin(); it!=indeg.end(); it++){
		if ((*it).second == 0){
			cout<<"zero deg "<<(*it).second<<endl;
			p.push((*it).first);
			}
		}  */
	
	queue<int> to;
	
	while (!p.empty()){
		int temp = p.top();
		p.pop();
		for(auto it=G[temp].begin(); it!=G[temp].end(); it++){
			indeg[(*it)] -= 1;
			if (indeg[(*it)]==0){
				p.push((*it));
				}
			}
		to.push(temp);
		}
		
	int parent[n+1];
	if ((int)to.size()==n){
		int prev = 0;
		while (!to.empty()){
			int curr = to.front();
			to.pop();
			parent[curr] = prev;
			prev = curr;
			}
		
		for(int i=1; i<=n; i++){
			cout<<parent[i]<<endl;
			}
		
		}
	else{
		cout<<"topo sort not exist"<<endl;
		}
		
	
	
	
	return 0;
	}
