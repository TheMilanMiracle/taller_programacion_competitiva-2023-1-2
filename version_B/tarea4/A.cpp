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
    return a+b;
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

    int search(int from, int val){
    if(!from) return search(0, 0, N-1, val);
    return search(0, 0, N-1, val+query(0, from-1));
  }

  int search(int n, int i, int j, int val){
    if(tree[n] < val) return -1;
    if(i==j && tree[n] >= val) return i;
    int mid = (i+j)/2;
    if(tree[2*n+1] >= val) return search(2*n+1, i, mid, val);
    else return search(2*n+2, mid+1, j, val-tree[2*n+1]);
  }
};

int main(){
  int n, a_i, in;

  cin >> n;
  vector<int> a(n),b(n,1);

  for(int i =0; i<n; i++){
    cin >> a_i;
    a[i] = a_i;
  }

  segment_tree tree(b);

  while(n){
    cin >> in;

    int idx = tree.search(0, in);

    tree.update(idx, 0);

    cout << a[idx] << " ";

    n--;
  }

    return 0;
}