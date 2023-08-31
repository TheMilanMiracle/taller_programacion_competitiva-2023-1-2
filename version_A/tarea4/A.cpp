#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		vector<int> miners, diamonds;
		
		cin >> n;
		n = n * 2;
		while(n--){
			int x, y;
			
			cin >> x >> y;
			
			if(x == 0){
				miners.push_back(abs(y));
				}
			if(y == 0){
				diamonds.push_back(abs(x));
				}
			}
		sort(miners.begin(),miners.end());
		sort(diamonds.begin(),diamonds.end());
		
		double R = 0;
		for(int i = 0; i < miners.size(); i++){
			R += sqrt( pow(miners[i],2) + pow(diamonds[i],2));
			}
		cout << fixed<<setprecision(9) << R << endl;
		}
	return 0;
	}
