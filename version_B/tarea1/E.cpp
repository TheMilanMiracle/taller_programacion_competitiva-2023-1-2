#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n, pi;
    cin >> x >> n;

    set<int> street; 
    multiset<int> mx;

    street.insert(x);
    street.insert(0);
    mx.insert(x);

    while(n--){
        cin  >> pi;
        street.insert(pi);

        auto itr = street.find(pi);
        auto prev_itr = prev(itr);
        auto next_itr = next(itr);

        mx.erase(mx.find(*next_itr - *prev_itr));
        mx.insert(pi - *prev_itr);
        mx.insert(*next_itr - pi);

        auto mxd = prev( mx.end() ); 

        cout << *mxd << " ";
    }


    return 0;
}