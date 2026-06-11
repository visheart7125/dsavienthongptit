#include<bits/stdc++.h>
using namespace std;

//ma tran ke sang danh sach ke cho ca 2 truong hop

int n, m, a[1001][1001];
vector<pair<int, int>> edge; //vector luu danh sach canh
vector<int> adj[1001];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j]){
				adj[i].push_back(j);
		}
	}
}
	for(int i = 1; i <= n; i++){
			for(int x : adj[i]){
				cout << x << " ";
			}
			cout << endl;
		}
}
