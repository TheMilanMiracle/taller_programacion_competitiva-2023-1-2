#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, si;
	
	
	cin >> t;
	
	while(t--){
		cin >> n;
		
		long long power = 0;
		priority_queue<int> bonus;
		
		while(n--){
			cin >> si;
			
			if(si){ //if s_i != 0
				
				bonus.push(si);
				
				}
			else{
				if(!bonus.empty()){
					power += bonus.top();
					bonus.pop();
					}
				
				}
			
			}
		
		
		cout << power << endl;
		}
	
	
	
	return 0;
	}

