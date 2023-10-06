#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, a, b , c;
    cin >> n >> a >> b >> c;

    vector<ll> dp(n+1, 0);
    vector<int> pieces(3);

    pieces[0] = a;
    pieces[1] = b;
    pieces[2] = c;

    //base case
    dp[0] = 0;

    for(int p = 1; p <= n; p++){
        ll ans = -1e8;
        for(int i = 0; i < 3; i++){
            if(p >= pieces[i]){
                ans = max(ans, dp[p - pieces[i]] + 1);
            }
        }
        
        dp[p] = ans;
    }

    cout << dp[n] << endl;
    
    return 0;
}