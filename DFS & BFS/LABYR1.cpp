using namespace std;

#include <iostream>
#include <queue>
#include <map>
#include <utility>

#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); i++)




int bfs(int i, int j,int r, int c,vector < vector <bool> >& visited, vector < vector <char> >& ch){
	//cout<<"now in bfs search"<<endl;
	map < pair <int,int>, int > sp;
	
	queue < pair <int,int> > q;
	q.push({i,j});
	visited[i][j] = true;
	sp[{i,j}] = 0;
	
	while (!q.empty()){
		pair <int,int> temp = q.front();
		q.pop();
		i = temp.first;
		j = temp.second;
		//cout<<"in queue "<<i<<" "<<j<<endl;
		
		if ((i-1 >=0)&&(!visited[i-1][j])&&(ch[i-1][j]=='.')){
			q.push({i-1,j});
			sp[{i-1,j}] = sp[{i,j}] + 1;
			visited[i-1][j] = true;
			}
		if ((i+1 <r)&&(!visited[i+1][j])&&(ch[i+1][j]=='.')){
			q.push({i+1,j});
			sp[{i+1,j}] = sp[{i,j}] + 1;
			visited[i+1][j]=true;
			}
		if ((j-1>=0)&&(!visited[i][j-1])&&(ch[i][j-1]=='.')){
			q.push({i,j-1});
			sp[{i,j-1}] = sp[{i,j}] + 1;
			visited[i][j-1]=true;
			}
		if ((j+1 <c)&&(!visited[i][j+1])&&(ch[i][j+1]=='.')){
			q.push({i,j+1});
			sp[{i,j+1}] = sp[{i,j}] + 1;
			visited[i][j+1]=true;
			}
		}
		int max = -1;
		tr(sp,it){
			int temp = (*it).second;
			if (temp>max){
				max = temp;
				}
			}
		return max;
	}


int main(){
	int t;
	cin>>t;
	
	while(t--){
		
	vector <int> ans;
	int c,r;
	cin>>c>>r;
	
	char ch[r+1][c+1];
	vector < vector <bool> > visited(1001, vector <bool> (1001, false));
	vector < vector <char> > cha;
	
	for(int i{0}; i<r; i++){
		cin>>ch[i];
		vector <char> t;
		int j=0;
		while (ch[i][j]){
			t.push_back(ch[i][j]);
			j++;
			}
		cha.push_back(t);
		}
		
	for(int i{0}; i<r; i++){
		for(int j{0}; j<c; j++){
			if (ch[i][j] == '.' && (!visited[i][j])){
				//cout<<"found . in ("<<i<<","<<j<<")"<<"\n";
				ans.push_back( bfs(i,j,r,c,visited,cha) );
				//cout<<"exit bfs"<<endl;
				break;
				}
			}
		}
		
	int max=-1;
	tr(ans,it){
		if ((*it)>max){
			max = (*it);
			//cout<<*it<<" ";
			}
		}
		cout<<"Maximum rope length is "<<max<<"."<<endl;
	
		
/*	for(int i{0}; i<r; i++){
		for(int j{0}; j<c; j++){
			cout<<ch[i][j]<<" ";
			}
			cout<<"\n";
		}
*/	
	visited.clear();
	ans.clear();
	cha.clear();
	}
	return 0;
	}
