#include<bits/stdc++.h>
using namespace std;

//dfs co huong

vector<int> adj[1005];
bool visited[1005];

void dfs(int u){
	visited[u] = true;
	cout << u << " ";
	for(int n : adj[u]){
		if(!visited[n]){
			dfs(n);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, u;
		cin >> n >> m >> u;
		for(int i = 1; i < n; i++) adj[i].clear();
		memset(visited, false, sizeof(visited));
		
		for(int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);

		}
		
		dfs(u);
		cout << "\n";
	}
}
