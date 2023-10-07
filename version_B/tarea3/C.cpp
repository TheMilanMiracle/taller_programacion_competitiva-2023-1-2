#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a_i;
    cin >> n >> x;

    vector<int> a(n), dp(n);

    for(int i = 0; i < n; i++){
        cin >> a_i;
        a[i] = a_i;
    }

    dp[n-1] = 1;

    int count = 1;
    for(int i = n-2; i >= 0; i--){
        if(a[i+1] - a[i] <= x){
            count++;    
        }
        else{
            count = 1;
        }
        dp[i] = max(count, dp[i+1]);
    }

    cout << dp[0] << endl;
    return 0;
}