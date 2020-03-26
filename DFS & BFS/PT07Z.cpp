using namespace std;
 
#include <iostream>
#include <unordered_map>
#include <queue>
 
#define tr(c,i) for(typeof(c.begin()) i = c.begin(); i!=c.end(); i++)
 
int bfs(unordered_map <int, vector<int> >& G, int, int);
 
int main(){
	int n;
	cin>>n;
	
	int a,b;
	unordered_map <int, vector<int> > G;
	for(int i{0}; i<(n-1);i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		}
 
	int k = bfs(G,n,1);
	int p = bfs(G,n,k);
	
	cout<<p<<endl;
	return 0;
	}
	
int bfs(unordered_map <int, vector<int> >& G, int n, int s){
	
	unordered_map <int,int> sp;
	
	vector <bool> seen(n, false);
	queue <int> q;
	q.push(s);
	seen[s] = true;
	sp[s] = 0;
 
	
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		tr(G[temp], it){
			if (!seen[*it]){
				seen[*it] = true;
				q.push(*it);
				sp[*it] = sp[temp] + 1;
				}
			}
		}
	int maximum = -1;
	int mkey = -1;
	tr(sp,it){
		int k = (*it).first;
		int v = (*it).second;
		if (v>maximum){
			maximum = v;
			mkey = k;
			}
		}
	if (s==1){
		return mkey;
		}
	else{
		return maximum;
		}
	}
