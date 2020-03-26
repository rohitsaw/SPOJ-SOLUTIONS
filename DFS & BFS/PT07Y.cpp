using namespace std;
 
#include <iostream>
#include <unordered_map>
#include <queue>
 
#define tr(c,i) for(typeof(c.begin()) i = c.begin(); i!=c.end(); i++)
 
int bfs(unordered_map <int, vector<int> >& G, int);
 
int main(){
	int n,m;
	cin>>n>>m;
	
	int a,b;
	unordered_map <int, vector<int> > G;
	for(int i{0}; i<m; i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		}
	int visited = bfs(G,n);
	if (visited == n && m == n-1){
		cout<<"YES";
		}
	else{
		cout<<"NO";
		}
		//cout<<visited;
	return 0;
	}
	
int bfs(unordered_map <int, vector<int> >& G, int n){
	
	int visited = 0;
	vector <bool> seen(n, false);
	queue <int> q;
	q.push(1);
	seen[1] = true;
	visited += 1;
	
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		tr(G[temp], it){
			if (!seen[*it]){
				seen[*it] = true;
				q.push(*it);
				visited += 1;
				}
			}
		}
	return visited;
	}
