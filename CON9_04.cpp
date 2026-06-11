#include<bits/stdc++.h>
using namespace std;

//danh sach ke sang ma tran ke cho ca 2 truong hop

int n, m, a[1001][1001];
vector<pair<int, int>> edge; //vector luu danh sach canh
vector<int> adj[1001]; // luu danh sach ke

int main(){
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s, num;
		getline(cin, s);
		stringstream ss(s);
		while(ss >> num){
			a[i][stoi(num)] = 1;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
		cout << a[i][j] << " ";
			}
		cout << endl;
	}
}
