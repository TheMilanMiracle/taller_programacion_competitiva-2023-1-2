#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

bool cookiesCount(ll k, vector<int> machines, int n, int t){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += k / machines[i];
        if(sum >= t){
            return true;
        }
    }
    return false;
}

int main(){
    int n, t, k_i;
    cin >> n >> t;

    vector<int> machines(n);

    for(int i = 0; i < n; i++){
        cin >> k_i;
        machines[i] = k_i;
    }

    ll i=1, j=1e18, k;
    while(i != j){
        k = (i+j)/2;
        if(cookiesCount(k, machines, n, t)) j = k;
        else i = k + 1;
    }

    cout << i << endl;
}
