#include<bits/stdc++.h>
using namespace std;

//dfs vo huong

int n, m, s, t;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			//ghi nhan v la cha cua u
			parent[v] = u;
			dfs(v);
		}
	}
}

void Path(int s, int t){
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	dfs(s);
	if(!visited[t]){
		cout << "-1";
	}
	else{
	vector<int> path;//truy vet duong di 
	//bat dau tu dinh t
	while(t != s){
		path.push_back(t);
		t = parent[t]; //lat nguoc lai
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	for(int x : path){
		cout << x << " ";
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	Path(s, t);
	}
}
