
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

main(){
	ll x1, y1, x2, y2, n, R = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	while(n--){
		ll a,b,c;
		cin >> a >> b >> c;
		if( ((a*x1 + b*y1 + c) < 0) != ((a*x2 + b*y2 + c) < 0)){
			R++;}
		}
	cout << R << endl;
	return 0;
	}