#include<bits/stdc++.h>
using namespace std;

//bfs co huong

int n, m;
vector<int> adj[1005];
bool visited [1005];

void bfs(int u){
	queue<int> q; //khoi tao
	q.push(u);
	visited[u] = true;
	//buoc lap
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(int x : adj[v]){
			if(!visited[x]){
			q.push(x);
			visited[x] = true;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int u; 
		cin >> n >> m >> u;
		for(int i = 1; i < n; i++) adj[i].clear();
		memset(visited, false, sizeof(visited));
		
		for(int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		bfs(u);
		cout << "\n";
	}
}
