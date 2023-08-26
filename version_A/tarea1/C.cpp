#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n;
    ll resp = 0;
    map<pair<ll, ll>, ll> mapa;
    map<ll, ll> mapay, mapax;
    cin >> n;
    for(int i =0; i < n; i++){
        ll x, y, xn, yn, xy;
        vector<ll> sumx, sumy, sumt;
        cin >> x >> y;
        mapax[x] += 1;
        mapay[y] += 1;
        mapa[make_pair(x,y)] += 1;
    }

    for(auto j = mapax.begin(); j != mapax.end(); j++){
        ll repeticion = j->second;
        resp += repeticion*(repeticion-1)/2;
    }
    for(auto k = mapay.begin(); k != mapay.end(); k++){
        ll repeticion = k->second;
        resp += repeticion*(repeticion-1)/2;
    }
    for(auto l = mapa.begin(); l != mapa.end(); l++){
        ll repeticion = l->second;
        resp -= repeticion*(repeticion-1)/2;
    }
    cout << resp;
}
