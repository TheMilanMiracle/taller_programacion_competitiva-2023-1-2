#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> grafo;
vector <int> visited;
vector <int> first;
map <int, int> magn;

void dfs(int s, vector <vector <int>> &grafo, vector <int> &visited){
    first[s] = s;
    magn[s] = 1;

    stack <int> Pila;                  
    Pila.push(s);

    while(!Pila.empty()){               
        int u = Pila.top(); Pila.pop();
        visited[u] = 1;

        for(int v: grafo[u]){
            if(visited[v] == 0){
                magn[s]++;
                first[v] = s;
                visited[v] = 1;
                Pila.push(v);
            }
        }
    }
}


main(){
    int n, m, k;
    cin >> n >> m;
    
    vector<int> c;
    grafo.assign(n, c);

    visited.assign(n, 0);
    first.assign(n, -1);

    while(m--){
        cin >> k;

        if (!k) continue;

        int f;
        cin >> f;
        f--;
        
        for (int i=0; i<k-1; i++) {
            int s;
            cin >> s;
            s--;
            
            grafo[f].push_back(s);
            grafo[s].push_back(f);

            f = s;
        }
    }

    for(int i = 0; i < n; i++){
        if(visited[i]==0){
            dfs(i, grafo, visited);
        }

        cout << magn[first[i]] << ' ';
    }

}