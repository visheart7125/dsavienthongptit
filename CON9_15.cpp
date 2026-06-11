#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];

void dfs(int u){
	visited[u] = true;
	for(int i : adj[u]){
		if(!visited[i]){
			dfs(i);
		}
	}
}

void tplt(){
	int ans = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl; //xuat ra so tplt
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		tplt();
	}
}
