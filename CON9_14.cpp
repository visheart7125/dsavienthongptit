#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int comp[1005];

void dfs(int u, int id){
    comp[u] = id;

    for(int v : adj[u]){
        if(comp[v] == 0){
            dfs(v, id);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            comp[i] = 0;
        }

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int id = 0;
        for(int i = 1; i <= n; i++){
            if(comp[i] == 0){
                ++id;
                dfs(i, id);
            }
        }

        int q;
        cin >> q;

        while(q--){
            int x, y;
            cin >> x >> y;

            if(comp[x] == comp[y])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
