#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		vector<vector<int>> adj(1005);
		cin >> v >> e;
		for(int i = 1; i <= e; i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for(int i = 1; i <= v; i++){
			sort(adj[i].begin(), adj[i].end());
			cout << i << ": ";
			for(int x : adj[i]){
				cout << x << " ";
			}
			cout << endl;
		}
	}
}
