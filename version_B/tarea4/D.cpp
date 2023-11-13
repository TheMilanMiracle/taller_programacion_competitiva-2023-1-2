#include <bits/stdc++.h>
using namespace std;

struct segment_tree{

  int N;
  vector <int> tree;
  
  segment_tree(vector <int> &A){
    // constructor
    N = A.size();
    tree.resize(4*N);
    build(0, 0, N-1, A);
  }

  int merge(int a, int b){
    return max(a,b);
  }

  void build(int n, int i, int j, vector <int> &A){
    // n: indice del nodo
    // nodo mira segmento [i,j]
    if(i == j){
      tree[n] = A[i];
      return;
    }
    int mid = (i+j)/2;
    // hijo izq: 2n+1
    // hijo der: 2n+2
    build(2*n+1, i, mid, A);
    build(2*n+2, mid+1, j, A);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  int query(int l, int r){
    return query(0, 0, N-1, l, r);
  }

  int query(int n, int i, int j, int l, int r){
    // nodo actual mira intervalo [i,j]
    // queremos responder consulta [l,r]
    // caso 1: contenido totalmente
    if(l <= i && j <= r){
      return tree[n];
    }
    // caso 2: [i,j] está fuera de [l,r]
    if(j < l || r < i){
      return 0;
    }
    // caso 3: contenido parcialmente
    int mid = (i+j)/2;
    return merge(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
  }

  void update(int idx, int x){
    // A[idx] = x
    update(0, 0, N-1, idx, x);
  }

  void update(int n, int i, int j, int idx, int x){
    // no contiene a idx
    if(idx < i || idx > j){
      return;
    }
    if(i == j){
      tree[n] = x;
      return;
    }
    int mid = (i+j)/2;
    update(2*n+1, i, mid, idx, x);
    update(2*n+2, mid+1, j, idx, x);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }
};

string Sigma = "abcdefghijklmnopqrstuvwxyz";
int sigma_len = 25;
vector<segment_tree> forest;

int main(){
  string input;
  int q, a, b;
  char c;
  cin >> input >> q;

  int input_len = input.length();

  for(int l = 0; l < sigma_len; l++){//fill forest
    vector<int> v(input_len);
    for(int i = 0; i<input_len; i++){
      input[i] == Sigma[l] ? v[i] = 1: v[i] = 0;
    }
      segment_tree t(v);
      forest.push_back(t);
    }

  while(q--){
    cin >> a;

    if(a == 2){
      int ocurrences = 0;
      cin >> a >> b;
            
      for(int i = 0; i<sigma_len;i++){
        ocurrences += forest[i].query(a-1,b-1);
      }
      cout << ocurrences << endl;
    }

    else{
      cin >> b >> c; 

      forest[input[b-1] - 'a'].update(b-1, 0);
      forest[c - 'a'].update(b-1, 1);

      input[b-1] = c;
    }

  }

  return 0;
}