#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, n, m;
	string t1, t2, tower;
	
	cin >> t;
	
	while(t--){
		int r = 0;
		cin >> n >> m;
		cin >> t1 >> t2; 
		
		reverse(t2.begin(), t2.end());
		
		tower = t1 + t2;
		
		for(int i = 0; i < n+m-1; i++){
			if(tower[i] == tower[i+1]){
				r += 1;
				}
			}
		if (r < 2){
			cout << "YES" << endl;
			}
		else{
			cout << "NO" << endl;
			}
		}
		return 0;
	}