#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grafo; //la lista de adyacencia
vector <int> dist; //para guardar la distancia
vector <int> parent; //para guardar el padre de cada nodo
const int b = 1e9;

void bfs(int s, int n){ //nodo inicial, cantidad de nodos
    dist.assign(n, b);
    parent.assign(n, -1);

    queue <int> Cola;
    dist[s] = 0;
    Cola.push(s);
    while(!Cola.empty()){
        int u = Cola.front(); Cola.pop();

        for( int v : grafo[u]){         //por cada vecino de u
            if(dist[v] == b){          //veo si ya lo visite
                dist[v] = min(dist[v],dist[u] + 1);  //guardo la distancia hasta v
                parent[v] = u;          //guardo el padre de v
                Cola.push(v);           //lo agrego a la cola
            }
        }
    }
}


main(){
    int n, m, k;
    cin >> n >> m;
    bool canReach = false;
 
    vector<int> v, track;
    grafo.assign(n,v);

    for(int i=0; i < m; i++){ //
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;

        grafo[n1].push_back(n2);
        grafo[n2].push_back(n1);
    }


    bfs(0,n);

    int l = n-1;
    track.push_back(l);
    while(parent[l] != -1){
        track.push_back(parent[l]);
        l = parent[l];
    }

    k = track.size();

    if(dist[n-1] != b){canReach = true;}

    if(!canReach){cout << "IMPOSSIBLE";}
    else{
        cout << k << endl;
        for (int t = k-1; t >= 0; t--)
        {
            cout << track[t]+1 << " ";
        }
        
    }
}