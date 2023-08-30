#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, x, ai, i = 0, j = 0, sum;
	cin >> n >> x;
	vector<pair<int, int>> v1(n), v2(n);
	
	for(int k = 0; k < n; k++){
		cin >> ai;
		v1[k] = make_pair(ai, k+1);
		}
	
	v2 = v1;
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(), v2.end(), greater());
	
	while(n--){
		sum = v1[i].first + v2[j].first;
		if((sum == x) && (v1[i].second != v2[j].second)){
			cout << v1[i].second << " " << v2[j].second << endl;
			return 0;
			}
		else if(sum > x){
			j++;
			}
		else{
			i++;
			}
		}
		
	cout << "IMPOSSIBLE" << endl;
	return 0;
}