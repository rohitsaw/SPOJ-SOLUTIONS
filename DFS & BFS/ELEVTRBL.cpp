#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> 
 
// #include <numeric>
 
using namespace std;
 
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
 
int bfs(int, int, int, int, int);
 
 
int main(){
	
	// taking inputs
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;	
	
	bfs(s,g,u,d,f);
	
	return 0;
	}
 
int bfs(int s,int g, int u, int d, int f){
	vector<bool> seen(1000001, false);
	queue<int> q;
	
	unordered_map<int, int> sp;
	
	q.push(s);
	seen[s] = true;
	sp[s] = 0;
	
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		
		int e1 = temp+u;
		int e2 = temp-d;
		
		if (e1 <= f && e1 != temp && !seen[e1]){
				seen[e1] = true;
				q.push(e1);
				sp[e1] = sp[temp] + 1;
				
			}
		if (e2 >= 1 && e2 != temp && !seen[e2]){
				seen[e2] = true;
				q.push(e2);
				sp[e2] = sp[temp] + 1;
			}
	}
		if (seen[g]){
			cout<<sp[g];
		}
		else{
			cout<<"use the stairs";
		}
	return 0;
}
