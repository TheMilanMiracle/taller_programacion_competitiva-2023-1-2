#include <iostream> //B//
#include <vector>
using namespace std;

int main(){
	int n ,h;
	cin >> n;
	cin >> h;
	vector<int> alturas(n);
	for (int i=0 ; i<n ; i++){
		cin >> alturas[i];
		}
	int vereda = 0;
	
	for(int j=0; j<n ; j++){
		if(alturas[j] <= h){
			vereda = vereda + 1;
			}
		else{
			vereda = vereda + 2;
			}
		}
	cout << vereda;
}










