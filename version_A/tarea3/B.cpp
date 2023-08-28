#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18;

main(){
    int n, m;
    cin >> n >> m ;

    vector <vector <pair<int,ll>>> graf(n);
    vector <int> optimalparent(n);

    while(m--){
        int u, v;
        ll w;

        cin >> u >> v >> w;
        u--;
        v--;

        graf[u].push_back({v,w});
        graf[v].push_back({u,w});
    }


    using state = pair<ll,int>;
    priority_queue <state, vector<state>, greater<state>> pq;
    vector <ll> dist(n, INF);

    pq.push({0,0});
	dist[0] = 0;

	while(!pq.empty()){
		auto [peso_camino, u] = pq.top();
		pq.pop();
		

		
		if(peso_camino != dist[u]) continue;

		for(auto [v, w] : graf[u]){
			if(peso_camino + w < dist[v]){
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
				optimalparent[v] = u;
			}
		}
	}
	
	if(dist[n-1] == INF){
		cout << "-1"; 
		return 0;
		}
	
	vector<int> respuesta;
	respuesta.push_back(n-1);
	 	
	int k = n-1;
	while(optimalparent[k] != 0){
		int out = optimalparent[k] ;
		respuesta.push_back(out);
		k = optimalparent[k];
		}
	
	respuesta.push_back(0);
	
	for(int p = respuesta.size()-1; p < respuesta.size(); p--){
		cout << respuesta[p] +1 << " ";
		
		}
}

