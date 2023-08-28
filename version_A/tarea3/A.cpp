#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18;

int main(){
	int n, m;
	ll c;
	cin >> n >> m;
	vector<vector <pair<int,ll>>> grafo(2*n);
	
	while(m--){
		int a, b;
		cin >> a >> b >> c;
		
		a--;
		b--;
		
		grafo[a].push_back({b,c});
		
		grafo[a+n].push_back({b+n,c});
		
		grafo[a].push_back({b+n,c/2});

	}
	
	
	using state = pair<ll,int>;
    priority_queue <state, vector<state>, greater<state>> pq;
    vector <ll> dist(2*n, INF);

    pq.push({0,0});
	dist[0] = 0;

	while(!pq.empty()){
		auto [peso_camino, u] = pq.top();
		pq.pop();
		
		if(peso_camino != dist[u]) continue;

		for(auto [v, w] : grafo[u]){
			if(peso_camino + w < dist[v]){
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
			}
		}
	}
	cout << dist[(2*n)-1] << endl;
	return 0;
}
