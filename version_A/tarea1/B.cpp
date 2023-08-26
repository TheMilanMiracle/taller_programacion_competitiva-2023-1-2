#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, num,l = 0, r = 0, resp = 0;
    cin >> N;
    set<int> s;
    vector<int> v(N);

    for(int i = 0; i<N;i++){
        cin >> num;
        v[i] = num;
    }
    for(r; r < N; r++){
        if(s.find(v[r]) != s.end()){
            while ((l < r) && (v[l] != v[r]))
            {
                s.erase(v[l]);
                l += 1;
            }
            resp = max(resp, int(s.size()));
            l += 1;
        }
        else{
            s.insert(v[r]);
            resp = max(resp, int(s.size()));
        }
    }
    cout << resp << endl;
}