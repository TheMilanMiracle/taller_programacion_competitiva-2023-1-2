#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q, k, n, a, b;
    cin >> q;

    while(q--){
        cin >> k >> n >> a >> b;
        long long i = 0, j = n, x;

        while(i != j){
            x = (i + j + 1) / 2;
            if((x *(a - b) + n * b) >= k) j = x - 1;
            else i = x;
        }

        if(i * a < k && (n-i) * b < k) cout << i << endl;
        else cout << -1 << endl;
    }

    return 0;
}