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
    return min(a,b);
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
      return 1e9;
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

int main(){
    int n, q, a_i, t, i, j;
    cin >> n >> q;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a_i;
        a[i] = a_i;
    }

    segment_tree tree(a);

    while(q--){
        cin >> t >> i >> j;
        
        if(t == 1){
          tree.update(i-1,j);
        }

        else{
          cout << tree.query(i-1, j-1) << endl;
        }
    }

  return 0;
}
