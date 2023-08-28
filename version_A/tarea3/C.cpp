#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct DSU{ 
    vector <int> parent, sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

ll kruskal(int n, vector<tuple<ll,int,int>> &edges, vector<int> &rel){
	DSU dsu(n);

	sort(edges.begin(), edges.end());

	ll ans = 0;
	for(auto [w, u, v] : edges){
		if(dsu.find_set(u) != dsu.find_set(v)){
			if(rel[v] == 0){
				ans += w;
				rel[v] = 1;
				dsu.union_set(u, v);
			}
		}
	}
	return ans;
}


int main(){
	int n, m;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
	int q;
	cin >> q;
	}
	
	cin >> m;
	
	vector <tuple<ll,int,int>> edges(m);
	vector <int> rel(n, 0);

	for(int i=0; i<m; i++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--;
		b--;
		edges[i] = {c, a, b};
	}
	ll kr = kruskal(n, edges, rel);
	int k = 0;
	for(int i = 0; i < n; i++){
		if(rel[i] == 0){
			k++;
			}
		}
	if(k != 1){
		cout << "-1";
		return 0;
		}
	cout << kr << '\n';
	return 0;
}
