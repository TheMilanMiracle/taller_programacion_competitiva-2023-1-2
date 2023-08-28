#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> grilla;
vector <int> visited;
vector <int> inputs;

void dfs(int s){
    if(visited[s]==0){
        visited[s] = 1;

        for(int v : grilla[s]){
            if(visited[v]==0){
                dfs(v);
            }
        }
    }
}


int main(){
    int n, xi, yi;
    vector<int> a;
    grilla.assign(2001,a);
    visited.assign(2001, 0);

    cin >> n;
    while(n--){ // agregando las relaciones de la tierra
        cin >> xi >> yi ;
        inputs.push_back(xi);
        grilla[xi].push_back(yi+1000);
        grilla[yi+1000].push_back(xi);
    }

    int componentes = 0;
    for(int i = 0; i < inputs.size(); i++){ // contando componentes (?)
        int nodo;
        nodo = inputs[i];
        if(visited[nodo]==0){
            componentes++;
            dfs(nodo);
        }
    }

    cout << componentes-1 << endl;
}
