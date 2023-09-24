#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x_i;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> x_i;
        arr[i] = x_i;
    }

    long long left = 1, right = 1e18, mid;
    while(left != right){
        mid = (left + right) / 2;

        long long sum = 0, count = 0;
        for(int i = 0; i < n; i++){

            if(count >= k || arr[i] > k) break;

            if(sum + arr[i] > mid){
                count ++;
                sum = 0;
            }

            sum += arr[i];
            
        }

        if(count >= k)left = mid + 1;
        else right = mid;
    }

    cout << left << endl;

    return 0;
}