#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
 
using namespace std;
 
#define tr(c,i) for(typeof(c.begin()) i=c.begin();i!=c.end();i++)
 
unordered_map <int, vector <int> > G;
unordered_map <int, int> indegree;
 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i{1}; i<=n; i++){
		indegree[i] = 0;
		}
	
	for(int i{0}; i<m; i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		indegree[y] += 1;
		}
/*		
		cout<<"print indegree"<<endl;
		tr(indegree,it){
			cout<<(*it).first<<" "<<(*it).second<<endl;
			}
*/		
		
		int count = 0;
		priority_queue <int, vector<int>, greater<int> > zd; 
		vector <int> to;
		tr(indegree,it){
			if ((*it).second==0){
				zd.push((*it).first);
				}
			}
/*			cout<<"print zd"<<endl;
			tr(zd,it){
				cout<<(*it)<<" "<<endl;
			}
*/			
			//make_heap(zd.begin(), zd.end(), greater<int>());
			
		//cout<<"staring popping"<<endl;
		while (!zd.empty()){
			int k = zd.top();
			zd.pop();
/*			tr(zd,it){
				cout<<(*it)<<" "<<endl;
				}
*/
			count += 1;
			tr(G[k],it){
				indegree[*it] -= 1;
				if (indegree[*it]==0){
					zd.push(*it);
				
					}
				}
			to.push_back(k);
			}
		if (count==n){
			tr(to,it){
				cout<<(*it)<<" ";
				}
			}
		else{
			cout<<"Sandro fails. ";
			}
		
	return 0;
	}
